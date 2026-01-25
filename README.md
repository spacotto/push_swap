# push_swap
A sorting algorithm implementation that sorts data on a stack using a limited set of instructions, with the goal of using the minimum number of operations possible. The project challenges you to choose and implement the most efficient algorithm for the task while dealing with algorithmic complexity.

Objective: given 2 stacks A and B, implement a sorting algorithm that sorts the numbers in stack A in ascending order using the least amount of operations.

## Instructions
Git clone this repository:
```
git clone https://github.com/spacotto/push_swap.git
```
Enter the directory:
```
cd push_swap
```
Compile through the Makefile located at the root:
```
make
```
Run the program as follows:
```
./push_swap 89 55 34 21 13 8 5 3 2 1 0  # The numbers can be whatever as long as they fit the validity criteria
```

## Invalid Inputs
1. Non-numeric parameters (only `int` are considered valid arguments).
```
./push_swap 0 one 2 3
```

2. Numeric parameters exceeding the `int` limits (INT_MIN, INT_MAX).
```
./push_swap 1 2 3 3333333333 4 5
```

3. Duplicate numeric parameters.
```
./push_swap 11 22 33 44 33 55
```

4. Empty string argument:
```
./push_swap "" 1
```

>[!CAUTION]
>In case of error, it must display `Error` followed by an `\n` on the **standard error**.

## Available Operations
| Operation                | Description                                                          |
| :----------------------- | :------------------------------------------------------------------- |
| `sa` (swap a)            | Swap the first 2 elements at the top of stack A                      |
| `sb` (swap b)            | Swap the first 2 elements at the top of stack B                      |
| `ss`                     | Execute sa and sb simultaneously                                     |
| `pa` (push a)            | Take the first element from stack B and put it at the top of stack A |
| `pb` (push b)            | Take the first element from stack A and put it at the top of stack B |
| `ra` (rotate a)          | Shift all elements of stack A up by 1 (first element becomes last)   |
| `rb` (rotate b)          | Shift all elements of stack B up by 1 (first element becomes last)   |
| `rr`                     | Execute ra and rb simultaneously                                     |
| `rra` (reverse rotate a) | Shift all elements of stack A down by 1 (last element becomes first) |
| `rrb` (reverse rotate b) | Shift all elements of stack B down by 1 (last element becomes first) |
| `rrr`                    | Execute rra and rrb simultaneously                                   |

## Benchmark Requirements
The `push_swap` project is evaluated based on its ability to sort datasets of varying sizes within strict operational limits. The benchmarks are designed to test both the algorithm's efficiency and its scalability across varying input sizes:

The algorithm's performance is measured by running multiple iterations with randomly generated numbers and calculating the average, minimum, and maximum operation counts. A successful implementation consistently stays well below these limits across all test cases.

| Set | Benchmark |
| :-- | :-------- |
| 5   | < 13      |
| 100 | < 700     |
| 500 | < 5500    |

## The Algorithm: Range Sort
The **Range Sort** (also known as **Sliding Window**) algorithm is a two-phase sorting approach designed to minimise the number of operations required to sort a stack. The algorithm works by dividing the input into **dynamic ranges** (or "windows") based on indexed values, pushing elements from stack A to stack B, and then pushing them back in sorted order.

### Phase 1: Pre-Sort
The first phase begins by indexing all numbers according to their relative position in the sorted sequence (smallest = 0, largest = n-1). Elements are then pushed to stack B whenever they fit the range requirement. Unlike static chunking (see **chunk sort**), the range algorithm uses a **sliding window approach**, continuously expanding the acceptable range as elements are pushed. 

For example, given a range of 30, our first target is any index between 0 and 29. After the first push, the range increases by 1. Now, our target is any index between 0 and 31.

Moreover, as elements are pushed to stack B, smaller values (those in the lower half of the current range) are rotated down using `rb` to maintain a roughly sorted order in stack B, which optimises the second phase.

Once only 3 elements are left in stack A (the biggest values in the stack), the presorting stops. The 3 elements are sorted on the spot. Then, phase 2 starts.

### Phase 2: Sort
In the second phase, elements are pushed back from stack B to stack A in descending order (largest first). The algorithm finds the largest remaining element in stack B, calculates the most efficient rotation path according to the target position (`rb` vs `rrb`), brings it to the top, and pushes it to stack A with `pa`. This process repeats until stack B is empty, leaving stack A sorted in ascending order.

>[!IMPORTANT]
>Check the **[flowchart](https://github.com/spacotto/push_swap/blob/main/flowchart.png)** to see a graphical representation of the algorithm.

# push_swap Tools
Several tools can help you test your `push_swap`. In this README.md I am going to present some options you might find useful:
1. The Checker
2. Premutations of 5
3. Performance
4. Visualizer
5. Complexity

>[!NOTE]
>The first three are included in this repository. The last two are external resources made by other 42 students.

## The Checker
The **checker** is a validation tool that verifies whether a sequence of operations correctly sorts a given stack. The official version (`checher_linux`) is provided by 42 as project material. However, the bonus part of the project asks the student to produce their own version of the checker.

### How it works
1. **Initialization.** Accepts stack A as command-line arguments (first argument = top of stack)
2. **Read Instructions.** Waits for operations from standard input, one per line (e.g., `sa`, `pb`, `rra`)
3. **Execute Operations.** Applies each instruction to the stacks in sequence
4. **Validate Result.** Checks if stack A is sorted in ascending order and stack B is empty
5. **Output Result.**
   - **`OK`** if the stack is correctly sorted
   - **`KO`** if the stack is not sorted or stack B is not empty
   - **`Error`** (to `stderr`) for invalid input (non-integers, duplicates, out-of-range values, invalid instructions)

### Invalid Inputs 
1. Non-numeric arguments:
```
./checker 4 67 one 87
Error
```

2. Numeric parameters exceeding the `int` limits (INT_MIN, INT_MAX):
```
./checker 2147483648
Error
```

3. Duplicate values:
```
./checker 3 2 1 3
Error
```

4. Empty string argument:
```
./checker "" 1
Error
```

4. Invalid instruction:
```
./checker 3 2 1
sa
pb
lol
Error
```

### How to use the checker
Just like push_swap, the checker takes a list of `int` as arguments.
```
./checker 3 2 1
```

Valid arguments will trigger the **interactive mode**. Now, you will have to provide the instructions. Once the instructions are given, press `CTRL+D` to close the interactive mode. Once the interactive mode is closed, the checker will receive the provided instructions and apply them to the list of `int`. If the provided instructions are valid, the checker will display either `OK` or `KO`. For example:  
```
./checker 2 1 3
sa               # Write the instruction, ENTER, CTRL+D
OK               # The Checker is going to display the result
```

### How to use the checker to test push_swap
Of course, the main purpose of the checker is to test the correct functioning of push_swap. 

In this case, you need to run push_swap and the checker with the same arguments. For example:
```
./push_swap 3 2 1 | ./checker 3 2 1
```

This way, the checker will read the instructions output by push_swap **without displaying them**. Thus, assuming that the arguments are valid, the output is going to be either `OK` or `KO`. For example:
```
./push_swap 2 1 3 | ./checker_linux 2 1 3
OK
```

## Permutations of 5
`permutation5.py` is a custom Python program not required by the subject. It tests all the possible permutations (combinations) of 5 values in 5 positions (aka !5 = 120). No arguments needed. Just launch the program:
```
python3 permutation5.py
```

Output example:
```
 ============================================================================
 Checking all possible 120 permutations of 5 (Ops limit: <=12)
 ============================================================================

 Progress status (%)
 ----------------------------------------------------------------------------
 100%

 Checker            Result
 ----------------------------------------------------------------------------
 checker_linux      120/120
 my_checker         120/120

 Parameter          Result
 ----------------------------------------------------------------------------
 Min ops            3
 Max ops            10
 Average            7.5
 Success            120/120
```

## Performance
`performance.py`is a custom Python program not required by the subject. It takes up to 3 arguments:
```
python3 performance.py [number_count] [iterations] [optional_limit]
```

For example:
```
python3 performance.py 500 100         # Tests 100 combinations of 500 random values
python3 performance.py 500 100 5500    # Tests 100 combinations of 500 random values where the maximum amount of ops accepted is 5500
```

Output example:
```
 ============================================================================
 Running 100 tests with 500 numbers (Ops limit: <5500)
 ============================================================================

 Progress status (%)
 ----------------------------------------------------------------------------
 100.0%

 Checker            Result
 ----------------------------------------------------------------------------
 checker_linux      100.0%
 my_checker         100.0%

 Parameter          Result
 ----------------------------------------------------------------------------
 Min ops            4632
 Max ops            5042
 Average            4876.5
 Success rate       100.0%
```

## [Visualizer](https://github.com/o-reo/push_swap_visualizer) (external)
A clean visualizer for your Push Swap Algorithm, you can't fix what you can't see! This is one of the oldest and most popular push_swap tools. 

## [Complexity](https://github.com/SimonCROS/push_swap_tester) (external)
With this tool, you can test the complexity and the performance of your `push_swap`'

# Resources
- [Sorting Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/sorting-algorithms/)
- [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
