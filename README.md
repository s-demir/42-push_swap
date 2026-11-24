*This project has been created as part of the 42 curriculum by sedemir.*

# push_swap

## Description

`push_swap` is a 42 Network project that challenges you to sort a stack of integers
using two stacks (`a` and `b`) and a restricted set of operations, with the goal of
using as few operations as possible.

**Allowed operations:**
| Operation | Effect |
|-----------|--------|
| `sa` | Swap the first two elements of stack a |
| `sb` | Swap the first two elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of b onto a |
| `pb` | Push top of a onto b |
| `ra` | Rotate a upward (top becomes bottom) |
| `rb` | Rotate b upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate a (bottom becomes top) |
| `rrb` | Reverse rotate b |
| `rrr` | `rra` and `rrb` simultaneously |

**Algorithm used:** Cost-based (Turk algorithm) — each element in stack `b` is
assigned a combined rotation cost to reach its target position in stack `a`. The
element with the lowest total cost is pushed first. This achieves:

- ≤ 3 ops for 3 numbers
- ≤ 12 ops for 5 numbers  
- ~550–650 ops for 100 random numbers (limit: 700)
- ~4200–5000 ops for 500 random numbers (limit: 5500)

## Instructions

### Compilation

```bash
# Compile push_swap (mandatory)
make

# Compile checker (bonus)
make bonus

# Clean object files
make clean

# Remove all binaries and objects
make fclean

# Recompile everything
make re
```

### Usage

```bash
# Sort integers given as separate arguments
./push_swap 3 2 1 4 5

# Sort integers given as a quoted string
./push_swap "3 2 1 4 5"

# Mix of formats
./push_swap "5 3" 2 "1 4"

# Use checker to verify push_swap output
./push_swap 3 2 1 | ./checker 3 2 1

# Manual checker usage
./checker 3 2 1
sa
pa
# (press Ctrl+D)
```

**Exit codes:**
- `0` — success
- `1` — invalid input (non-numeric, out of INT range, duplicate, empty string)

**Output:**
- `push_swap` prints each operation on its own line to stdout, nothing if already sorted
- `checker` prints `OK` if stack is sorted correctly, `KO` otherwise, `Error` on bad input/command

### Benchmark

```bash
# Generate random numbers and count operations
ARG=$(shuf -i 1-200 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l

ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

## Resources

- [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) — visual debugging tool
- [The Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — cost-based sorting explanation
- [42 Norminette](https://github.com/42School/norminette) — official coding standard checker

### AI Usage in this Project

Artificial intelligence (Claude by Anthropic via Antigravity IDE) was used in the
following stages of this project:

1. **Architecture design** — generating the file/module structure and determining which
   functions belong in which `.c` files, respecting the 5-function-per-file limit.
2. **Algorithm selection** — explaining cost-based sorting and helping calculate target
   index assignment logic for the Turk algorithm.
3. **Code generation** — producing Norminette-compliant C code (25-line function limit,
   no `for`/`switch`/ternary, tab indentation, 80-char line limit, proper headers).
4. **Debugging** — identifying off-by-one errors in `rotate_min_to_top` and incorrect
   `above_mid` calculations in `assign_cost`.
5. **Benchmark testing** — writing shell one-liners to measure operation counts across
   3, 5, 100 and 500 element inputs and validating against project thresholds.

All generated code was reviewed, understood, and validated by sedemir before submission.
