#!/usr/bin/env python3

import subprocess
import random
import sys

# --- CONFIGURATION ---
PUSH_SWAP_PATH = "./push_swap"
CHECKER_LINUX_PATH = "./checker_linux"
MY_CHECKER_PATH = "./checker"
ERROR_LOG_FILE = "error_log.txt"

def generate_random_numbers(count):
    """Generates a list of unique random integers."""
    return random.sample(range(-2147483648, 2147483647), count)

def run_checker(checker_path, args_str, operations):
    """Runs a checker program and returns True if output is 'OK'."""
    try:
        # Run: echo "operations" | ./checker args
        process = subprocess.run(
            f'echo "{operations}" | {checker_path} {args_str}',
            shell=True,
            capture_output=True,
            text=True
        )
        return process.stdout.strip() == "OK"
    except:
        return False

def run_test(num_count, ops_limit, iterations, log_errors=False):
    # Color codes
    GREEN = "\033[92m"
    RED = "\033[91m"
    CYAN = "\033[0;96m"
    RESET = "\033[0m"
    
    print(f"\n--- Running {iterations} tests with {num_count} numbers (Ops limit: {CYAN}<{ops_limit + 1}{RESET}) ---")

    failures = 0
    total_ops = 0
    max_ops_seen = 0
    min_ops_seen = float('inf') # Initialize with infinity
    checker_linux_ok = 0
    my_checker_ok = 0

    # Clear log file if logging is enabled
    if log_errors:
        with open(ERROR_LOG_FILE, "w") as f:
            f.write(f"--- Error Log for {num_count} numbers ---\n")

    for i in range(1, iterations + 1):
        numbers = generate_random_numbers(num_count)
        args = [str(n) for n in numbers]
        args_str = ' '.join(args)

        try:
            # Run push_swap
            process = subprocess.run([PUSH_SWAP_PATH] + args, capture_output=True, text=True)
            output = process.stdout.strip()

            # Count operations
            if not output:
                ops_count = 0
            else:
                ops_count = len(output.split('\n'))

            total_ops += ops_count
            max_ops_seen = max(max_ops_seen, ops_count)
            min_ops_seen = min(min_ops_seen, ops_count) # Update minimum

            # Run checker_linux
            if run_checker(CHECKER_LINUX_PATH, args_str, output):
                checker_linux_ok += 1

            # Run my_checker
            if run_checker(MY_CHECKER_PATH, args_str, output):
                my_checker_ok += 1

            # Check if too many ops
            if ops_count > ops_limit:
                failures += 1
                if log_errors:
                    with open(ERROR_LOG_FILE, "a") as f:
                        f.write(f"Test {i}: {ops_count} moves. Numbers: {args_str}\n")

            # Visual progress
            print(f"\rTest {i}/{iterations}", end="")
            sys.stdout.flush()

        except Exception as e:
            print(f"\nError running test {i}: {e}")
            return

    # Final results
    print() # New line after progress
    
    # checker_linux results
    checker_linux_color = GREEN if checker_linux_ok == iterations else RED
    print(f"checker_linux {checker_linux_color}{checker_linux_ok}/{iterations}{RESET}")
    
    # my_checker results
    my_checker_color = GREEN if my_checker_ok == iterations else RED
    print(f"my_checker {my_checker_color}{my_checker_ok}/{iterations}{RESET}")

    # Results section
    avg = total_ops / iterations
    # --- Logic for colors
    min_ops_color = GREEN if min_ops_seen <= ops_limit else RED
    max_ops_color = GREEN if max_ops_seen <= ops_limit else RED
    avg_color = GREEN if avg <= ops_limit else RED
    failures_color = GREEN if failures == 0 else RED
    
    print(f"\nResults for {num_count} numbers:")
    print(f"Min ops: {min_ops_color}{min_ops_seen if min_ops_seen != float('inf') else 0}{RESET} ops")
    print(f"Max ops: {max_ops_color}{max_ops_seen}{RESET} ops")
    print(f"Average: {avg_color}{avg:.1f}{RESET} ops")
    print(f"Failures: {failures_color}{failures}{RESET}/{iterations}")
   
    # Error log section
    if log_errors and failures > 0:
        print(f"\n--- Errors logged to {ERROR_LOG_FILE} ---")

if __name__ == "__main__":
    # Check if push_swap exists
    try:
        subprocess.run([PUSH_SWAP_PATH], capture_output=True)
    except FileNotFoundError:
        print("Error: ./push_swap not found. Compile it first!")
        sys.exit(1)

    # 1. Run 100 loops with 5 numbers (Limit <=12)
    run_test(num_count=5, ops_limit=12, iterations=100, log_errors=False)
    
    # 2. Run 100 loops with 100 numbers (Limit <700)
    run_test(num_count=100, ops_limit=699, iterations=100, log_errors=False)

    # 3. Run 100 loops with 500 numbers (Limit <5500)
    run_test(num_count=500, ops_limit=5499, iterations=100, log_errors=True)
