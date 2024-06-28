# Dynamic Programming


## Introduction

Dynamic programming is a method for solving complex problems by breaking them down into simpler subproblems. It is applicable to problems that exhibit the properties of overlapping subproblems and optimal substructure. The main idea is to solve each subproblem only once and store the solutions for future reference, thus avoiding the computation of the same subproblem multiple times.

## Key Concepts

1. **Overlapping Subproblems:**
   - A problem is said to have overlapping subproblems if the problem can be broken down into subproblems which are reused several times.
   - Example: Fibonacci sequence.

2. **Optimal Substructure:**
   - A problem has an optimal substructure if an optimal solution to the problem contains optimal solutions to the subproblems.
   - Example: Shortest path in a graph.

## Used Techniques

### 1. Memoization (Top-Down Approach)

Memoization is a technique where we store the results of expensive function calls and reuse the cached result when the same inputs occur again. This is typically implemented with recursion.

## Solved Problems Summary

### 1. Cut Pieces Problem

The goal is to find the optimal cut sequence for a marble slab in order to produce the most valuable set of pieces.<br>
The initial slab and pieces dimensions as well as each piece value are given in the input.<br>
Find all this problem details [here](./cut-pieces-problem/).