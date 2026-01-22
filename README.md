# push_swap
A sorting algorithm implementation that sorts data on a stack using a limited set of instructions, with the goal of using the minimum number of operations possible. The project challenges you to choose and implement the most efficient algorithm for the task while dealing with algorithmic complexity.

## Objective
Given 2 stacks A and B, implement a sorting algorithm that sorts the numbers in stack A in ascending order using the least amount of operations.

### Invalid Inputs
>[!IMPORTANT]
>In case of error, it must display "Error" followed by an ’\n’ on the standard error.

Invalid input cases:
1. Non numeric parameters (only `int` are considered valid arguments).
2. Duplicate numeric parameters.
3. Numeric parameters exceeding the `int` limits (INT_MIN, INT_MAX).


### Available Operations
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

### Benchmark
| Set | Max operations |
| :-- | :------------- |
| 5   | 12             |
| 100 | < 700          |
| 500 | < 5500         |

## Chunk Algorithm
The **Chunk Algorithm** (also known as the **Segmented Sorting approach**) is an efficient method for sorting larger datasets by dividing the problem into manageable segments.

### How It Works
1. **Divide into Chunks.** The algorithm divides the input into multiple chunks based on their relative value ranges. For example, with 100 numbers, you might create 5 chunks of 20 numbers each.

2. **Push to Stack B.** Elements are pushed from stack A to stack B in chunks, starting with the smallest values. As each chunk is identified, its elements are moved to stack B while maintaining a rough ordering.

3. **Strategic Positioning.** While pushing elements to stack B, the algorithm decides whether to use `pb` (leaving element at top) or `pb + rb` (rotating element down) based on the element's value relative to what remains. This creates a semi-sorted stack B.

4. **Push Back Optimally.** Once all elements are in stack B, the algorithm finds the largest remaining element in stack B and calculates the most efficient way to bring it to the top (using either `rb` or `rrb`, whichever requires fewer operations).
  
5. **Final Push.** The largest elements are pushed back to stack A one by one, resulting in a fully sorted stack. 

### Chunk Size Optimization and Disorder

The chunk algorithm's efficiency depends heavily on the **chunk size**, which must be balanced between Phase 1 (pushing to stack B) and Phase 2 (pushing back to stack A). **Disorder** measures how unsorted the input is. High disorder (many inversions) indicates a highly unsorted or reverse-sorted input.

**Smaller chunks** create more chunks with fewer elements each. This results in a **more sorted stack B** because elements are pushed in tighter groups, making Phase 2 efficient—finding the largest element requires fewer rotations. However, Phase 1 suffers because managing many chunks means more time searching through stack A to locate chunk members, increasing rotation operations.

**Larger chunks** reduce the number of chunks, making Phase 1 faster since there's less overhead switching between chunks and searching for members. However, this causes elements in stack B to be **more scattered**, making Phase 2 slower as finding the largest element requires more rotations through a less organized stack.

The optimal chunk size depends on the input's **initial disorder**. For **low-disorder inputs** (already somewhat sorted), larger chunks work best because Phase 1 is naturally easier and the extra Phase 2 cost is minimal. For **high-disorder inputs** (reverse sorted or very random), smaller chunks help by keeping stack B organized, which is critical when Phase 2 becomes the bottleneck.

## Resources
- [Sorting Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/sorting-algorithms/)
- [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
