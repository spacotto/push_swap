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

def run_checker(checker_path, args_str, operations):
    """Runs a checker program and returns True if output is 'OK'."""
    try:
        # Ensure operations ends with a newline if it's not empty
        if operations and not operations.endswith('\n'):
            operations += '\n'
            
        process = subprocess.run(
            [checker_path] + args_str.split(),
            input=operations,
            capture_output=True,
            text=True,
            timeout=5
        )
        return "OK" in process.stdout
    except:
        return False

def run_permutation_test(num_count, ops_limit):
    """Exhaustively tests all permutations. Skips logic for already-sorted cases."""
    GREEN = "\033[92m"
    RED = "\033[91m"
    CYAN = "\033[0;96m"
    RESET = "\033[0m"

    base_numbers = list(range(num_count))
    permutations = list(itertools.permutations(base_numbers))
    total_tests = len(permutations)
    sorted_tuple = tuple(sorted(base_numbers))
    
    print(f"\n--- Running {iterations} tests with {num_count} numbers (Ops limit: {CYAN}<{ops_limit + 1}{RESET}) ---")

    failures = []
    checker_linux_ok = 0
    my_checker_ok = 0
    total_ops = 0
    max_ops = 0
    min_ops = float('inf')

    for i, p in enumerate(permutations, 1):
        # --- NEW CONDITION: SKIP SORTED CASE ---
        if p == sorted_tuple:
            checker_linux_ok += 1
            my_checker_ok += 1
            min_ops = min(min_ops, 0)
            # We don't increment total_ops or max_ops for a skip
            print(f"\rTest {i}/{total_tests}    run_test(num_count=100, ops_limit=699, iterations=100, log_errors=False)
", end="")
            continue
        # ---------------------------------------

        args_list = [str(n) for n in p]
        args_str = ' '.join(args_list)
        
        try:
            process = subprocess.run([PUSH_SWAP_PATH] + args_list, capture_output=True, text=True)
            output = process.stdout.strip()
            ops_count = len(output.split('\n')) if output else 0
            
            total_ops += ops_count
            max_ops = max(max_ops, ops_count)
            min_ops = min(min_ops, ops_count)

            if run_checker(CHECKER_LINUX_PATH, args_str, output):
                checker_linux_ok += 1
            else:
                failures.append(f"KO (Checker): {args_str}")

            if run_checker(MY_CHECKER_PATH, args_str, output):
                my_checker_ok += 1
            
            if ops_count > ops_limit:
                failures.append(f"Limit Exceeded ({ops_count} ops): {args_str}")

            print(f"\rTest {i}/{total_tests}", end="")
            sys.stdout.flush()
        except Exception as e:
            print(f"\nError: {e}")

    print("\n")
    c_lin_color = GREEN if checker_linux_ok == total_tests else RED
    c_my_color = GREEN if my_checker_ok == total_tests else RED
    print(f"checker_linux {c_lin_color}{checker_linux_ok}/{total_tests}{RESET}")
    print(f"my_checker    {c_my_color}{my_checker_ok}/{total_tests}{RESET}")
    
    # Avg calculation (excluding the 1 skipped sorted case from the divisor for accuracy)
    avg = total_ops / (total_tests - 1) if total_tests > 1 else 0
    
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

if __name__ == "__main__":
    with open(ERROR_LOG_FILE, "w") as f:
        f.write("--- PUSH_SWAP TESTER LOG ---\n")

    try:
        subprocess.run([PUSH_SWAP_PATH], capture_output=True)
    except FileNotFoundError:
        print(f"Error: {PUSH_SWAP_PATH} not found.")
        sys.exit(1)

    run_permutation_test(5, 11)
