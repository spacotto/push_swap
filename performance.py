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

# Standard ANSI Color codes
ANSI_GRAY   = "\033[1;90m"
ANSI_RED    = "\033[0;91m"
ANSI_GREEN  = "\033[0;92m"
ANSI_YELLOW = "\033[0;93m"
ANSI_BLUE   = "\033[0;94m"
ANSI_MAGENTA= "\033[0;95m"
ANSI_CYAN   = "\033[0;96m"
ANSI_WHITE  = "\033[0;97m"
RESET       = "\033[0m"

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

def run_test(num_count, iterations, limit=None, cb_mode=False):
    # Dynamic Color Assignment
    if cb_mode:
        COLOR_PASS = ANSI_CYAN
        COLOR_FAIL = ANSI_YELLOW
    else:
        COLOR_PASS = ANSI_GREEN
        COLOR_FAIL = ANSI_RED
    
    # "No limit" color logic
    COLOR_NEUTRAL = ANSI_MAGENTA if limit is None else ANSI_YELLOW

    # Clear old log if it exists
    if os.path.exists(LOG_FILE):
        os.remove(LOG_FILE)
        
    print(f"\n ============================================================================")
    limit_display = limit if limit is not None else "None"
    print(f" Running {ANSI_GRAY}{iterations}{RESET} tests with {ANSI_GRAY}{num_count}{RESET} numbers (Limit: {ANSI_GRAY}{limit_display}{RESET})")
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
            
            is_sorted = run_checker(CHECKER_LINUX_PATH, args_str, output)
            if is_sorted: checker_linux_ok += 1
            if run_checker(MY_CHECKER_PATH, args_str, output): my_checker_ok += 1
            
            if is_sorted and (limit is None or ops_count <= limit):
                success_count += 1
            elif limit is not None and ops_count > limit:
                log_error(ops_count, numbers)
            
            print(f"\r {ANSI_GRAY}{(i / iterations) * 100:.1f}%{RESET}", end="", flush=True)
        except Exception:
            continue
    
    print("\n")
    avg = total_ops / iterations if iterations > 0 else 0
    success_rate = (success_count / iterations) * 100 if iterations > 0 else 0
    
    # Checker Table
    linux_color = COLOR_PASS if (checker_linux_ok / iterations) == 1.0 else COLOR_FAIL
    my_color = COLOR_PASS if (my_checker_ok / iterations) == 1.0 else COLOR_FAIL

    print(f" Checker            Result")
    print(f" ----------------------------------------------------------------------------")
    print(f" checker_linux      {linux_color}{(checker_linux_ok/iterations)*100:.1f}%{RESET}")
    print(f" my_checker         {my_color}{(my_checker_ok/iterations)*100:.1f}%{RESET}")
    
    # Parameter Table
    def get_val_color(val):
        if limit is None: return COLOR_NEUTRAL
        return COLOR_PASS if val <= limit else COLOR_FAIL

    print(f"\n Parameter          Result")
    print(f" ----------------------------------------------------------------------------")
    print(f" Min ops            {get_val_color(min_ops)}{min_ops}{RESET}")
    print(f" Max ops            {get_val_color(max_ops)}{max_ops}{RESET}")
    print(f" Average            {get_val_color(avg)}{avg:.1f}{RESET}")
    
    success_color = COLOR_PASS if success_rate == 100.0 else COLOR_FAIL
    print(f" Success rate       {success_color}{success_rate:.1f}%{RESET}\n")

def main():
    if len(sys.argv) < 4:
        print("Usage: python3 performance.py [on/off] [number_count] [iterations] [optional_limit]")
        sys.exit(1)
    
    cb_mode = sys.argv[1].lower() == "on"
    
    try:
        num_count = int(sys.argv[2])
        iterations = int(sys.argv[3])
        limit = int(sys.argv[4]) if len(sys.argv) > 4 else None
    except ValueError:
        print("Error: Arguments must be integers (except for colorblind on/off)")
        sys.exit(1)
    
    run_test(num_count, iterations, limit, cb_mode)

if __name__ == "__main__":
    main()
