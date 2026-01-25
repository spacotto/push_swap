#!/usr/bin/env python3

import subprocess
import sys
import itertools

# --- CONFIGURATION ---
PUSH_SWAP_PATH = "./push_swap"
CHECKER_LINUX_PATH = "./checker_linux"
MY_CHECKER_PATH = "./checker"
ERROR_LOG_FILE = "error_log_5.txt"

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
    """Exhaustively tests all permutations of 5 numbers."""
    GREEN = "\033[0;92m"
    RED = "\033[0;91m"
    CYAN = "\033[1;96m"
    RESET = "\033[0m"

    # Generate all 120 permutations
    base_numbers = list(range(num_count))
    permutations = list(itertools.permutations(base_numbers))
    total_tests = len(permutations)
    sorted_tuple = tuple(sorted(base_numbers))

    print(f"\n ============================================================================")
    print(f"\n Checking all possible {CYAN}120 permutations of 5{RESET} (Ops limit: {CYAN}<{ops_limit + 1}{RESET})")
    print(f"\n ============================================================================")
    print(f" Progress status")
    print(f" ----------------------------------------------------------------------------")
    
    failures = []
    checker_linux_ok = 0
    my_checker_ok = 0
    total_ops = 0
    max_ops = 0
    min_ops = float('inf') 

    for i, p in enumerate(permutations, 1):
        # Exclude 0 1 2 3 4 from statistics to avoid 0-op bias
        if p == sorted_tuple:
            checker_linux_ok += 1
            my_checker_ok += 1
            # Visual update for the skip
            print(f"\rTest {i}/{total_tests}", end="")
            continue
        
        args_list = [str(n) for n in p]
        args_str = ' '.join(args_list)
        
        try:
            # Run push_swap
            process = subprocess.run([PUSH_SWAP_PATH] + args_list, capture_output=True, text=True)
            output = process.stdout.strip()
            
            # Count operations
            ops_count = len(output.split('\n')) if output else 0
            
            # Update stats for non-sorted cases
            total_ops += ops_count
            max_ops = max(max_ops, ops_count)
            min_ops = min(min_ops, ops_count)

            # Check validity with official checker
            if run_checker(CHECKER_LINUX_PATH, args_str, output):
                checker_linux_ok += 1
            else:
                failures.append(f"KO (Checker): {args_str}")

            # Check validity with your own checker
            if run_checker(MY_CHECKER_PATH, args_str, output):
                my_checker_ok += 1
            
            # Check efficiency
            if ops_count > ops_limit:
                failures.append(f"Limit Exceeded ({ops_count} ops): {args_str}")

            # Visual progress
            print(f"\r {i}/{total_tests}", end="")
            sys.stdout.flush()
        except Exception as e:
            print(f"\nError on permutation {args_str}: {e}")

    # Final Results Printout
    print("\n")
    
    c_lin_color = GREEN if checker_linux_ok == total_tests else RED
    c_my_color = GREEN if my_checker_ok == total_tests else RED

    print(f"\n Checker            Result")
    print(f" ----------------------------------------------------------------------------")
    print(f"checker_linux        {c_lin_color}{checker_linux_ok}/{total_tests}{RESET}")
    print(f"my_checker           {c_my_color}{my_checker_ok}/{total_tests}{RESET}")
    
    # Calculate average using 119 tests (excluding sorted case)
    effective_count = total_tests - 1
    avg = total_ops / effective_count if effective_count > 0 else 0
    
    print(f" Parameter          Result")
    print(f" ----------------------------------------------------------------------------")
    print(f"Min ops            {min_ops if min_ops != float('inf') else 0}")
    print(f"Max ops            {max_ops}")
    print(f"Average            {avg:.1f}")
    
    failures_color = RED if failures else GREEN
    print(f"Failures: {failures_color}{len(failures)}{RESET}/{total_tests}")

    # Write errors to file if any found
    if failures:
        with open(ERROR_LOG_FILE, "w") as f:
            f.write(f"--- Failures for {num_count} numbers ---\n")
            for fail in failures:
                f.write(fail + "\n")
        print(f"\n--- Errors logged to {ERROR_LOG_FILE} ---")

if __name__ == "__main__":
    # Check for executable
    try:
        subprocess.run([PUSH_SWAP_PATH], capture_output=True)
    except FileNotFoundError:
        print(f"Error: {PUSH_SWAP_PATH} not found. Compile it first!")
        sys.exit(1)

    # Run for 5 numbers, limit < 12 ops (11)
    run_permutation_test(5, 11)
