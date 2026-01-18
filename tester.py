#!/usr/bin/env python3

import subprocess
import random
import sys

# --- CONFIGURATION ---
PUSH_SWAP_PATH = "./push_swap"
CHECKER_LINUX_PATH = "./checker_linux"
MY_CHECKER_PATH = "./checker"  # Your own checker
ERROR_LOG_FILE = "error_log.txt"

def generate_random_numbers(count):
    """Generates a list of unique random integers."""
    return random.sample(range(-2147483648, 2147483647), count)

def run_checker(checker_path, args, operations):
    """Runs a checker program and returns True if output is 'OK'."""
    try:
        process = subprocess.run(
            [checker_path] + args,
            input=operations,
            capture_output=True,
            text=True
        )
        return process.stdout.strip() == "OK"
    except:
        return False

def run_test(num_count, max_ops, iterations, log_errors=False):
    # Color codes
    GREEN = "\033[92m"
    RED = "\033[91m"
    RESET = "\033[0m"
    
    # Check if limit is respected for coloring
    limit_color = GREEN if max_ops >= 699 else RED
    if num_count == 500:
        limit_color = GREEN if max_ops >= 5499 else RED
    
    print(f"\n--- Running {iterations} tests with {num_count} numbers (Max Ops: {limit_color}{max_ops}{RESET}) ---")

    failures = 0
    total_ops = 0
    checker_linux_ok = 0
    my_checker_ok = 0

    # Clear log file if logging is enabled
    if log_errors:
        with open(ERROR_LOG_FILE, "w") as f:
            f.write(f"--- Error Log for {num_count} numbers ---\n")

    for i in range(1, iterations + 1):
        numbers = generate_random_numbers(num_count)
        args = [str(n) for n in numbers]

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

            # Run checker_linux
            if run_checker(CHECKER_LINUX_PATH, args, output):
                checker_linux_ok += 1

            # Run my_checker
            if run_checker(MY_CHECKER_PATH, args, output):
                my_checker_ok += 1

            # Check if too many ops
            if ops_count > max_ops:
                failures += 1
                if log_errors:
                    with open(ERROR_LOG_FILE, "a") as f:
                        f.write(f"Test {i}: {ops_count} moves. Numbers: {' '.join(args)}\n")

            # Visual progress
            print(f"\rTest {i}/{iterations}", end="")
            sys.stdout.flush()

        except Exception as e:
            print(f"\nError running test {i}: {e}")
            return

    # Final results
    print()  # New line after progress
    
    # checker_linux results
    checker_linux_color = GREEN if checker_linux_ok == iterations else RED
    print(f"checker_linux {checker_linux_color}{checker_linux_ok}/{iterations}{RESET}")
    
    # my_checker results
    my_checker_color = GREEN if my_checker_ok == iterations else RED
    print(f"my_checker {my_checker_color}{my_checker_ok}/{iterations}{RESET}")

    avg = total_ops / iterations
    print(f"\nResults for {num_count} numbers:")
    print(f"Average: {avg:.1f} ops")
    print(f"Failures: {failures}")
    if log_errors and failures > 0:
        print(f"Errors logged to {ERROR_LOG_FILE}")

if __name__ == "__main__":
    # Check if push_swap exists
    try:
        subprocess.run([PUSH_SWAP_PATH], capture_output=True)
    except FileNotFoundError:
        print("Error: ./push_swap not found. Compile it first!")
        sys.exit(1)

    # 1. Run 100 loops with 100 numbers (Limit 700)
    run_test(num_count=100, max_ops=699, iterations=100, log_errors=False)

    # 2. Run 100 loops with 500 numbers (Limit 5500)
    run_test(num_count=500, max_ops=5499, iterations=100, log_errors=True)
```

**Key changes:**

1. **Added `run_checker` function** - Runs any checker program and returns True if result is "OK"

2. **Track checker results** - Counts how many tests pass for each checker

3. **Color-coded max_ops** - Green if within limit, red if not

4. **Removed per-test ops count** - Only shows "Test X/Y" progress

5. **Added checker output lines**:
   - `checker_linux X/Y` (green if all OK, red if any KO)
   - `my_checker X/Y` (same logic)

**Output will look like:**
```
--- Running 100 tests with 100 numbers (Max Ops: 699) ---
Test 100/100
checker_linux 100/100  # Green if all OK
my_checker 100/100     # Green if all OK

Results for 100 numbers:
Average: 599.4 ops
Failures: 0
