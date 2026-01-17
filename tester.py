#!/usr/bin/env python3

import subprocess
import random
import sys

# --- CONFIGURATION ---
PUSH_SWAP_PATH = "./push_swap"  # Path to your executable
CHECKER_PATH = "./checker_linux" # Path to checker (optional, if you have it)
ERROR_LOG_FILE = "error_log.txt"

def generate_random_numbers(count):
    """Generates a list of unique random integers."""
    return random.sample(range(-2147483648, 2147483647), count)

def run_test(num_count, max_ops, iterations, log_errors=False):
    print(f"\n--- Running {iterations} tests with {num_count} numbers (Max Ops: {max_ops}) ---")

    failures = 0
    total_ops = 0

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

            # Count operations (lines of output)
            if not output:
                ops_count = 0
            else:
                ops_count = len(output.split('\n'))

            total_ops += ops_count

            # Validation logic
            status = "OK"
            if ops_count > max_ops:
                status = "FAIL (Too many ops)"
                failures += 1
                if log_errors:
                    with open(ERROR_LOG_FILE, "a") as f:
                        f.write(f"Test {i}: {ops_count} moves. Numbers: {' '.join(args)}\n")

            # Visual progress bar
            color = "\033[92m" if status == "OK" else "\033[91m" # Green or Red
            print(f"\rTest {i}/{iterations}: {color}[{ops_count} ops]{'\033[0m'} ", end="")
            sys.stdout.flush()

        except Exception as e:
            print(f"\nError running test {i}: {e}")
            return

    avg = total_ops / iterations
    print(f"\n\nResults for {num_count} numbers:")
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

    # 1. Run 20 loops with 100 numbers (Limit 700)
    run_test(num_count=100, max_ops=699, iterations=100, log_errors=False)

    # 2. Run 100 loops with 500 numbers (Limit 5500) -> Logs to file
    run_test(num_count=500, max_ops=5499, iterations=100, log_errors=True)
