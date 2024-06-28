# Problem Description

A study is being conducted to understand the transmission of infectious diseases within the Portuguese population. The goal is to find the maximum number of hops an infection can make through social interactions, using data from a social network.

## Problem Context

The task involves analyzing the worst-case scenario for the spread of an infection in Portugal. The assumption is that individuals who are directly or indirectly connected become infected instantaneously. The social network is represented as a directed graph, where nodes are individuals and edges represent direct acquaintances.

## Input

The input file contains information about the social network:

- The first line contains two integers: \( n \) (number of individuals\) and \( m \) (number of relationships\).
- The next \( m \) lines each contain two integers \( x \) and \( y \), indicating that individual \( x \) knows individual \( y \).

Each integer in a line is separated by exactly one space, with no other characters except the end of the line. Assume the input graphs are directed and potentially cyclic.

## Output

The program should output an integer \( s \), representing the maximum number of hops an infection can make in the TugaNet network.

### Example 1

**Input:**
```
7 8
3 4
3 2
4 6
4 5
6 2
6 5
5 7
2 7
```

**Output:**
```
4
```

## Implementation

The project should preferably be implemented using C, C++, or Rust. Submissions in Java/Python are also accepted but strongly discouraged. Students choosing Java/Python should be aware that their solutions might not pass all tests even if the correct algorithm is implemented. Recursive solutions may exceed stack limits on larger tests, so iterative algorithms are recommended.

The required implementation time is less than 15 hours.

**Compilation Parameters:**

For C++:
```
g++ -std=c++11 -O3 -Wall file.cpp -lm
```

For C:
```
gcc -O3 -ansi -Wall file.c -lm
```

For Java:
```
javac File.java
java -Xss32m -Xmx256m -classpath . File
```

For Python:
```
python3 file.py
```