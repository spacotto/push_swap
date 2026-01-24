# push_swap
A sorting algorithm implementation that sorts data on a stack using a limited set of instructions, with the goal of using the minimum number of operations possible. The project challenges you to choose and implement the most efficient algorithm for the task while dealing with algorithmic complexity.

### Objective
Given 2 stacks A and B, implement a sorting algorithm that sorts the numbers in stack A in ascending order using the least amount of operations.

## Invalid Inputs
1. Non-numeric parameters (only `int` are considered valid arguments).
```
./push_swap 0 one 2 3
```

2. Duplicate numeric parameters.
```
./push_swap 11 22 33 44 33 55
```

3. Numeric parameters exceeding the `int` limits (INT_MIN, INT_MAX).
```
./push_swap 1 2 3 3333333333 4 5
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

![flowchart](https://github.com/spacotto/push_swap/blob/main/flowchart.png)

## The Checker (Bonus)

## Resources
- [Sorting Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/sorting-algorithms/)
- [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
