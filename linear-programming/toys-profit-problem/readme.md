# Problem Description

You have been hired by CompanyInc in Lisbon, Portugal, to develop a program that estimates the maximum profit obtainable from the production and sale of toys during Christmas.

## Problem Context

CompanyInc produces a set of N wooden toys daily \(\{x_1, ..., x_N\}\), where each toy \( x_i \) has a profit \( p_i \). There are production constraints for each toy due to assembly line restrictions, and the total number of toys produced per day is limited by the forest cutting constraints. This Christmas, besides selling each toy individually, the company will also sell special packages containing three different toys, which yield a higher profit than the sum of their individual profits.

## Objective

The goal is to determine the maximum daily profit obtainable from the production and sale of toys and special packages. The solution should be implemented in Python using the PuLP library for linear programming problems.

## Input

The input file contains information about the toys, their profits, and the company's production capacity:

- The first line contains three integers: \( t \) (number of different toys), \( p \) (number of special packages), and \( m \) (maximum number of toys producible per day).
- A list of \( N \) lines follows, each containing two integers \( l_i \) (profit of toy \( i \)) and \( c_i \) (production capacity of toy \( i \)).
- A list of \( p \) lines follows, each containing four integers \( i, j, k, p_{ijk} \), indicating the special package profit \( p_{ijk} \) and the names of the toys \( i, j, k \) that make up the package.

## Output

The program should output an integer corresponding to the maximum daily profit Rudolf can obtain.

### Example 1

**Input:**
```
5 2 150
50 27
30 33
45 30
40 37
35 35
1 3 5 130
2 3 4 130
```

**Output:**
```
6440
```

### Example 2

**Input:**
```
5 2 15
50 27
30 33
45 30
40 37
35 35
1 3 5 129
2 3 4 130
```

**Output:**
```
750
```


## Implementation

The project must be implemented in Python. The required implementation time is less than 15 hours. The PuLP library should be installed using the command:

```
python -m pip install pulp
```

You must have a linear programming solver installed, such as [GLPK](https://www.gnu.org/software/glpk/) or LP_solve. To install [GLPK](https://www.gnu.org/software/glpk/) (for example, on Ubuntu):
```
sudo apt-get install glpk-utils
```

### Execution Parameters:

To run the program, use:
```
python3 yourprogram.py < input_file
```