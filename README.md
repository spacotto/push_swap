# push_swap
A sorting algorithm implementation that sorts data on a stack using a limited set of instructions, with the goal of using the minimum number of operations possible. The project challenges you to choose and implement the most efficient algorithm for the task while dealing with algorithmic complexity.

### Objective
Given 2 stacks A and B, implement a sorting algorithm that sorts the numbers in stack A in ascending order using the least amount of operations.

## Invalid Inputs
Invalid input cases:
1. Non-numeric parameters (only `int` are considered valid arguments).
2. Duplicate numeric parameters.
3. Numeric parameters exceeding the `int` limits (INT_MIN, INT_MAX).

>[!IMPORTANT]
>In case of error, it must display "Error" followed by an ’\n’ on the standard error.

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

## Benchmark
| Set | Max operations |
| :-- | :------------- |
| 5   | 12             |
| 100 | < 700          |
| 500 | < 5500         |

## The Algorithm: The Sliding Window

[!flowchart](https://github.com/spacotto/push_swap/blob/main/flowchart.png)

## The Checker (Bonus)

## Resources
- [Sorting Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/sorting-algorithms/)
- [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
