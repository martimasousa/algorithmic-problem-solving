# Problem Description

An engineer has been hired by a factory to optimize their marble cutting process. The goal is to cut a marble slab into pieces required by clients, prioritizing pieces of higher value. The marble slab can be cut vertically or horizontally, and the resulting pieces can either be cut further or removed if they meet the required dimensions or cannot be used.

## Input

The input file contains the dimensions of the marble slab and the dimensions of the requested pieces:

- The first line contains two positive integers \(X\) and \(Y\), separated by a space, representing the dimensions of the slab.
- The second line contains a positive integer \(n\), indicating the number of types of pieces that can be produced.
- The next \(n\) lines describe each type of piece, each line containing three positive integers \(a_i\), \(b_i\), and \(p_i\) separated by a space, where \(a_i, b_i\) are the dimensions of the piece and \(p_i\) is the price of the piece.

## Output

The output should be the maximum value obtainable from the given slab. If no piece can be produced, the output should be 0.

## Examples

### Example 1

**Input:**
```
1 3
2
1 1 1
1 3 10
```

**Output:**
```
10
```


### Example 2

**Input:**
```
3 20
3
2 2 4
1 5 10
3 7 20
```

**Output:**
```
120
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