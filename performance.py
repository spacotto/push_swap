#!/usr/bin/env python3

import subprocess
import random
import sys
import os

# --- CONFIGURATION ---
PUSH_SWAP_PATH = "./push_swap"
CHECKER_LINUX_PATH = "./checker_linux"
MY_CHECKER_PATH = "./checker"
LOG_FILE = "error_log.txt"

# Color codes
GREEN = "\033[0;92m"
RED = "\033[0;91m"
CYAN = "\033[1;96m"
YELLOW = "\033[0;93m"
RESET = "\033[0m"

def log_error(ops_count, numbers):
    """Logs failing sequences to error_log in the specified format"""
    with open(LOG_FILE, "a") as f:
        f.write(f"\nTotal operations: {ops_count}")
        f.write(f"\nSet of numbers tested:\n\n")
        f.write(" ".join(map(str, numbers)) + "\n\n")
        f.write(f"----------------------------------------------------------------------------\n")

def generate_random_numbers(count):
    """Generates a list of unique random integers"""
    return random.sample(range(-2147483648, 2147483647), count)

def run_checker(checker_path, args_str, operations):
    """Runs a checker program and returns True if output is 'OK'"""
    try:
        process = subprocess.run(
            f'echo "{operations}" | {checker_path} {args_str}',
            shell=True, capture_output=True, text=True, timeout=5
        )
        return process.stdout.strip() == "OK"
    except:
        return False

def run_test(num_count, iterations, limit=None):
    # Clear old log if it exists
    if os.path.exists(LOG_FILE):
        os.remove(LOG_FILE)
        
    print(f"\n ============================================================================")
    limit_display = limit if limit is not None else "None"
    print(f" Running {CYAN}{iterations}{RESET} tests with {CYAN}{num_count}{RESET} numbers (Limit: {CYAN}{limit_display}{RESET})")
    print(f" ============================================================================\n") 
    print(f" Progress status (%)")
    print(f" ----------------------------------------------------------------------------")
    
    total_ops = 0
    min_ops = float('inf')
    max_ops = 0
    checker_linux_ok = 0
    my_checker_ok = 0
    success_count = 0
    
    for i in range(1, iterations + 1):
        numbers = generate_random_numbers(num_count)
        args_str = ' '.join(map(str, numbers))
        
        try:
            process = subprocess.run([PUSH_SWAP_PATH] + list(map(str, numbers)), capture_output=True, text=True, timeout=5)
            output = process.stdout.strip()
            ops_count = len(output.split('\n')) if output else 0
            
            total_ops += ops_count
            min_ops = min(min_ops, ops_count)
            max_ops = max(max_ops, ops_count)
            
            # Check correctness
            is_sorted = run_checker(CHECKER_LINUX_PATH, args_str, output)
            if is_sorted:
                checker_linux_ok += 1
            if run_checker(MY_CHECKER_PATH, args_str, output):
                my_checker_ok += 1
            
            # Success logic: Sorted correctly AND (no limit OR under limit)
            if is_sorted and (limit is None or ops_count <= limit):
                success_count += 1
            elif limit is not None and ops_count > limit:
                log_error(ops_count, numbers)
            
            print(f"\r {CYAN}{(i / iterations) * 100:.1f}%{RESET}", end="", flush=True)
        except Exception:
            continue
    
    print("\n")
    avg = total_ops / iterations if iterations > 0 else 0
    success_rate = (success_count / iterations) * 100 if iterations > 0 else 0
    
    # Checker Table - Green if 100%, else Red
    linux_color = GREEN if (checker_linux_ok / iterations) == 1.0 else RED
    my_color = GREEN if (my_checker_ok / iterations) == 1.0 else RED

    print(f" Checker            Result")
    print(f" ----------------------------------------------------------------------------")
    print(f" checker_linux      {linux_color}{(checker_linux_ok/iterations)*100:.1f}%{RESET}")
    print(f" my_checker         {my_color}{(my_checker_ok/iterations)*100:.1f}%{RESET}")
    
    # Parameter Table
    def get_val_color(val):
        if limit is None: return YELLOW
        return GREEN if val <= limit else RED

    print(f"\n Parameter          Result")
    print(f" ----------------------------------------------------------------------------")
    print(f" Min ops            {get_val_color(min_ops)}{min_ops}{RESET}")
    print(f" Max ops            {get_val_color(max_ops)}{max_ops}{RESET}")
    print(f" Average            {get_val_color(avg)}{avg:.1f}{RESET}")
    
    # Success rate - Green if 100%, else Red
    success_color = GREEN if success_rate == 100.0 else RED
    print(f" Success rate       {success_color}{success_rate:.1f}%{RESET}\n")

def main():
    if len(sys.argv) < 3:
        print("Usage: python3 performance.py [number_count] [iterations] [optional_limit]")
        sys.exit(1)
    
    try:
        num_count = int(sys.argv[1])
        iterations = int(sys.argv[2])
        limit = int(sys.argv[3]) if len(sys.argv) > 3 else None
    except ValueError:
        print("Error: Arguments must be integers")
        sys.exit(1)
    
    run_test(num_count, iterations, limit)

if __name__ == "__main__":
    main()
