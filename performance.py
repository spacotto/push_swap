#!/usr/bin/env python3

import subprocess
import random
import sys
import time

# --- CONFIGURATION ---
PUSH_SWAP_PATH = "./push_swap"
CHECKER_LINUX_PATH = "./checker_linux"
MY_CHECKER_PATH = "./checker"

# Color codes
GREEN = "\033[92m"
RED = "\033[91m"
CYAN = "\033[0;96m"
YELLOW = "\033[93m"
RESET = "\033[0m"

def get_ops_limit(num_count):
    """Get operation limit based on number count"""
    if num_count <= 5:
        return 12
    elif num_count <= 100:
        return 699
    else:
        return 5499

def generate_random_numbers(count):
    """Generates a list of unique random integers"""
    return random.sample(range(-2147483648, 2147483647), count)

def run_checker(checker_path, args_str, operations):
    """Runs a checker program and returns True if output is 'OK'"""
    try:
        process = subprocess.run(
            f'echo "{operations}" | {checker_path} {args_str}',
            shell=True,
            capture_output=True,
            text=True,
            timeout=5
        )
        return process.stdout.strip() == "OK"
    except:
        return False

def run_test(num_count, iterations):
    ops_limit = get_ops_limit(num_count)
    
    print(f"\n--- Running {iterations} tests with {num_count} numbers (Ops limit: {CYAN}<{ops_limit + 1}{RESET}) ---")
    
    # Stats tracking
    total_ops = 0
    min_ops = float('inf')
    max_ops = 0
    checker_linux_ok = 0
    my_checker_ok = 0
    success_count = 0
    
    for i in range(1, iterations + 1):
        numbers = generate_random_numbers(num_count)
        args = [str(n) for n in numbers]
        args_str = ' '.join(args)
        
        try:
            # Run push_swap
            process = subprocess.run(
                [PUSH_SWAP_PATH] + args,
                capture_output=True,
                text=True,
                timeout=5
            )
            output = process.stdout.strip()
            
            # Count operations
            if not output:
                ops_count = 0
            else:
                ops_count = len(output.split('\n'))
            
            total_ops += ops_count
            min_ops = min(min_ops, ops_count)
            max_ops = max(max_ops, ops_count)
            
            # Check if within limit
            if ops_count <= ops_limit:
                success_count += 1
            
            # Run checker_linux
            if run_checker(CHECKER_LINUX_PATH, args_str, output):
                checker_linux_ok += 1
            
            # Run my_checker
            if run_checker(MY_CHECKER_PATH, args_str, output):
                my_checker_ok += 1
            
            # Calculate progress percentage
            progress = (i / iterations) * 100
            
            # Print live updates (overwrite same line)
            print(f"Testing status: \r{progress:.1f}%\n", end="", flush=True)
        
        except subprocess.TimeoutExpired:
            print(f"\n{RED}Timeout on test {i}{RESET}")
            continue
        except Exception as e:
            print(f"\n{RED}Error on test {i}: {e}{RESET}")
            continue
    
    print()  # New line after progress
    
    # Calculate final stats
    avg = total_ops / iterations if iterations > 0 else 0
    success_rate = (success_count / iterations) * 100 if iterations > 0 else 0
    checker_linux_rate = (checker_linux_ok / iterations) * 100 if iterations > 0 else 0
    my_checker_rate = (my_checker_ok / iterations) * 100 if iterations > 0 else 0
    
    # Print checker results
    checker_linux_color = GREEN if checker_linux_ok == iterations else RED
    my_checker_color = GREEN if my_checker_ok == iterations else RED
    
    print(f"checker_linux {checker_linux_color}{checker_linux_rate:.1f}%{RESET}")
    print(f"my_checker {my_checker_color}{my_checker_rate:.1f}%{RESET}")
    
    # Print results
    print()
    min_color = GREEN if min_ops <= ops_limit else RED
    max_color = GREEN if max_ops <= ops_limit else RED
    avg_color = GREEN if avg <= ops_limit else RED
    success_color = GREEN if success_rate == 100.0 else RED
    
    print(f"Min ops: {min_color}{min_ops}{RESET} ops")
    print(f"Max ops: {max_color}{max_ops}{RESET} ops")
    print(f"Average: {avg_color}{avg:.1f}{RESET} ops")
    print(f"{success_color}{success_rate:.1f}%{RESET} success rate")

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 tester.py [number_count] [iterations]")
        print("Example: python3 tester.py 100 50")
        sys.exit(1)
    
    try:
        num_count = int(sys.argv[1])
        iterations = int(sys.argv[2])
    except ValueError:
        print("Error: Arguments must be integers")
        sys.exit(1)
    
    # Check if push_swap exists
    try:
        subprocess.run([PUSH_SWAP_PATH], capture_output=True, timeout=1)
    except FileNotFoundError:
        print(f"Error: {PUSH_SWAP_PATH} not found. Compile it first!")
        sys.exit(1)
    except:
        pass
    
    # Run the test
    run_test(num_count, iterations)

if __name__ == "__main__":
    main()
