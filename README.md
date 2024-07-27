# Push Swap

## Introduction:
Push Swap is a sorting algorithm project at 42 that challenges participants to sort a stack of numbers with a limited set of actions in the most efficient way possible. The project aims to develop problem-solving skills, algorithmic thinking, and efficient coding practices.

## Objective:
The objective of Push Swap is to implement a program that sorts a stack of integers using two stacks and a limited set of operations. The goal is to perform the sorting using as few operations as possible.

The allowed operations are:
- sa: swap the first two elements at the top of stack A.
- sb: swap the first two elements at the top of stack B.
- ss: perform sa and sb simultaneously.
- pa: push the top element from stack B to stack A.
- pb: push the top element from stack A to stack B.
- ra: rotate stack A (shift all elements up by one).
- rb: rotate stack B (shift all elements up by one).
- rr: perform ra and rb simultaneously.
- rra: reverse rotate stack A (shift all elements down by one).
- rrb: reverse rotate stack B (shift all elements down by one).
- rrr: perform rra and rrb simultaneously.

## Usage:

Compilation: Use make to compile the program
```bash
make -j
```
Execution: Run the program with a list of unique integers as arguments.  
For example:
```bash
./push_swap 5 3 8 1
```

## Rules:

The program operates with two stacks, A and B.  
Initially, stack A contains the integers given as arguments, which need to be sorted in ascending order.  
Stack B is empty initially.  
The operations used to sort stack A must be printed on the standard output.
