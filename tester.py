#!/usr/bin/env python3

import subprocess
import random
import sys
import itertools

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

def run_permutation_test(num_count, ops_limit):
    """Exhaustively tests all permutations for small sets (like 3 or 5 numbers)."""
    GREEN = "\033[92m"
    RED = "\033[91m"
    CYAN = "\033[0;96m"
    RESET = "\033[0m"

    base_numbers = list(range(num_count))
    permutations = list(itertools.permutations(base_numbers))
    total_tests = len(permutations)
    
    print(f"\n--- Running Exhaustive Test: {num_count} numbers ({total_tests} combinations) ---")
    print(f"Ops limit: {CYAN}<{ops_limit + 1}{RESET}")

    failures = []
    checker_linux_ok = 0
    my_checker_ok = 0
    total_ops = 0
    max_ops = 0
    min_ops = float('inf')

    for i, p in enumerate(permutations, 1):
        args_str = ' '.join(map(str, p))
        
        try:
            process = subprocess.run([PUSH_SWAP_PATH] + list(map(str, p)), capture_output=True, text=True)
            output = process.stdout.strip()
            ops_count = len(output.split('\n')) if output else 0
            
            total_ops += ops_count
            max_ops = max(max_ops, ops_count)
            min_ops = min(min_ops, ops_count)

            # Check validity
            linux_res = run_checker(CHECKER_LINUX_PATH, args_str, output)
            if linux_res:
                checker_linux_ok += 1
            else:
                failures.append(f"KO (Checker): {args_str}")

            if run_checker(MY_CHECKER_PATH, args_str, output):
                my_checker_ok += 1
            
            # Check efficiency
            if ops_count > ops_limit:
                failures.append(f"Limit Exceeded ({ops_count} ops): {args_str}")

            print(f"\rTest {i}/{total_tests}", end="")
            sys.stdout.flush()
        except Exception as e:
            print(f"\nError: {e}")

    print("\n")
    # Display Results
    c_lin_color = GREEN if checker_linux_ok == total_tests else RED
    c_my_color = GREEN if my_checker_ok == total_tests else RED
    print(f"checker_linux {c_lin_color}{checker_linux_ok}/{total_tests}{RESET}")
    print(f"my_checker    {c_my_color}{my_checker_ok}/{total_tests}{RESET}")
    
    avg = total_ops / total_tests
    print(f"\nResults for {num_count} numbers:")
    print(f"Min ops: {min_ops} ops")
    print(f"Max ops: {max_ops} ops")
    print(f"Average: {avg:.1f} ops")
    print(f"Failures: {RED if failures else GREEN}{len(failures)}{RESET}/{total_tests}")

    if failures:
        with open(ERROR_LOG_FILE, "a") as f:
            f.write(f"\n--- Failures for {num_count} numbers ---\n")
            for fail in failures:
                f.write(fail + "\n")
        print(f"Detailed errors written to {ERROR_LOG_FILE}")

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
    min_ops_seen = float('inf') 
    checker_linux_ok = 0
    my_checker_ok = 0

    if log_errors:
        with open(ERROR_LOG_FILE, "a") as f:
            f.write(f"\n--- Error Log for {num_count} numbers ---\n")

    for i in range(1, iterations + 1):
        numbers = generate_random_numbers(num_count)
        args = [str(n) for n in numbers]
        args_str = ' '.join(args)

        try:
            process = subprocess.run([PUSH_SWAP_PATH] + args, capture_output=True, text=True)
            output = process.stdout.strip()
            ops_count = len(output.split('\n')) if output else 0

            total_ops += ops_count
            max_ops_seen = max(max_ops_seen, ops_count)
            min_ops_seen = min(min_ops_seen, ops_count)

            if run_checker(CHECKER_LINUX_PATH, args_str, output):
                checker_linux_ok += 1
            if run_checker(MY_CHECKER_PATH, args_str, output):
                my_checker_ok += 1

            if ops_count > ops_limit:
                failures += 1
                if log_errors:
                    with open(ERROR_LOG_FILE, "a") as f:
                        f.write(f"Test {i}: {ops_count} moves. Numbers: {args_str}\n")

            print(f"\rTest {i}/{iterations}", end="")
            sys.stdout.flush()
        except Exception as e:
            print(f"\nError: {e}")
            return

    print()
    checker_linux_color = GREEN if checker_linux_ok == iterations else RED
    print(f"checker_linux {checker_linux_color}{checker_linux_ok}/{iterations}{RESET}")
    my_checker_color = GREEN if my_checker_ok == iterations else RED
    print(f"my_checker {my_checker_color}{my_checker_ok}/{iterations}{RESET}")

    avg = total_ops / iterations
    print(f"\nResults for {num_count} numbers:")
    print(f"Min ops: {min_ops_seen} ops")
    print(f"Max ops: {max_ops_seen} ops")
    print(f"Average: {avg:.1f} ops")
    print(f"Failures: {RED if failures > 0 else GREEN}{failures}{RESET}/{iterations}")

if __name__ == "__main__":
    # Clear log file at start
    with open(ERROR_LOG_FILE, "w") as f:
        f.write("--- PUSH_SWAP TESTER LOG ---\n")

    try:
        subprocess.run([PUSH_SWAP_PATH], capture_output=True)
    except FileNotFoundError:
        print(f"Error: {PUSH_SWAP_PATH} not found.")
        sys.exit(1)

    # 1. Exhaustive check for 5 numbers (All 120 combinations)
    run_permutation_test(5, 11)

    # 2. Random check for 100 numbers
    run_test(100, 699, 100, log_errors=True)

    # 3. Random check for 500 numbers
    run_test(500, 5499, 100, log_errors=True)
