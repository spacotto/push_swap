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
    """Exhaustively tests all permutations with specific color formatting."""
    GREEN = "\033[0;92m"
    RED = "\033[0;91m"
    CYAN = "\033[1;96m"
    RESET = "\033[0m"

    base_numbers = list(range(num_count))
    permutations = list(itertools.permutations(base_numbers))
    total_tests = len(permutations)
    sorted_tuple = tuple(sorted(base_numbers))

    print(f"\n ============================================================================")
    print(f" Checking all possible {CYAN}120 permutations of 5{RESET} (Ops limit: {CYAN}<=12{RESET})")
    print(f" ============================================================================\n")
    print(f" Progress status (%)")
    print(f" ----------------------------------------------------------------------------")
    
    failures = []
    checker_linux_ok = 0
    my_checker_ok = 0
    total_ops = 0
    max_ops = 0
    min_ops = float('inf') 

    for i, p in enumerate(permutations, 1):
        # Progress update in %
        print(f"\r {CYAN}{int((i/total_tests)*100)}%{RESET}", end="")
        sys.stdout.flush()

        if p == sorted_tuple:
            checker_linux_ok += 1
            my_checker_ok += 1
            continue
        
        args_list = [str(n) for n in p]
        args_str = ' '.join(args_list)
        
        try:
            process = subprocess.run([PUSH_SWAP_PATH] + args_list, capture_output=True, text=True)
            output = process.stdout.strip()
            ops_count = len(output.split('\n')) if output else 0
            
            total_ops += ops_count
            max_ops = max(max_ops, ops_count)
            min_ops = min(min_ops, ops_count)
            
            # 0 1 2 3 4 (sorted permutation) is counted as correct by default
            if run_checker(CHECKER_LINUX_PATH, args_str, output):
                checker_linux_ok += 1
            else:
                failures.append(f"KO (Checker): {args_str}")

            if run_checker(MY_CHECKER_PATH, args_str, output):
                my_checker_ok += 1
            
            if ops_count > ops_limit:
                failures.append(f"Limit Exceeded ({ops_count} ops): {args_str}")

        except Exception as e:
            pass

    print("\n\n Checker            Result")
    print(f" ----------------------------------------------------------------------------")
    
    # Only color the 1st value (numerator)
    c_lin_color = GREEN if checker_linux_ok == total_tests else RED
    c_my_color = GREEN if my_checker_ok == total_tests else RED
    print(f" checker_linux      {c_lin_color}{checker_linux_ok}{RESET}/{total_tests}")
    print(f" my_checker         {c_my_color}{my_checker_ok}{RESET}/{total_tests}")
    
    effective_count = total_tests - 1
    avg = total_ops / effective_count if effective_count > 0 else 0
    
    print(f"\n Parameter          Result")
    print(f" ----------------------------------------------------------------------------")
    
    # Conditional coloring: Green if <= limit, else Red
    def color_val(val):
        return f"{GREEN if val <= ops_limit else RED}{val}{RESET}"

    print(f" Min ops            {color_val(min_ops if min_ops != float('inf') else 0)}")
    print(f" Max ops            {color_val(max_ops)}")
    print(f" Average            {color_val(round(avg, 1))}")
    
    success_count = total_tests - len(failures)
    s_color = GREEN if success_count == total_tests else RED
    print(f" Success            {s_color}{success_count}{RESET}/{total_tests}")

if __name__ == "__main__":
    run_permutation_test(5, 12)
