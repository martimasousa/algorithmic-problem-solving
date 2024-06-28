#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> boardSize;
vector<vector<int>> calculatedValues;

/**
 * This function tests all the possible cuts (in the specified direction) and returns the best
 * possible value.
 */
int cut(int boardWidth, int boardHeight, string cutDirection) {
    int maxValue = calculatedValues[boardWidth][boardHeight];

    if (cutDirection == "vertical") {
        int middlePos = (boardWidth % 2 == 0) ? (boardWidth / 2) : (boardWidth / 2 + 1);

        for (int cutPos = 1; cutPos <= middlePos; cutPos++) {
            int newValue = calculatedValues[cutPos - 1][boardHeight] + calculatedValues[boardWidth - cutPos][boardHeight];
            
            maxValue = (newValue > maxValue) ? newValue : maxValue;
        }
    } else if (cutDirection == "horizontal") {
        int middlePos = (boardHeight % 2 == 0) ? (boardHeight / 2) : (boardHeight / 2 + 1);

        for (int cutPos = 1; cutPos <= middlePos; cutPos++) { 
            int newValue = calculatedValues[boardWidth][cutPos - 1] + calculatedValues[boardWidth][boardHeight - cutPos];

            maxValue = (newValue > maxValue) ? newValue : maxValue;
        }
    }

    return maxValue;
}

/**
 * This function checks if a given coordinate is inside the initial board.
 */
bool isInBounds(int line, int column) {
    return (line < boardSize[0] && column < boardSize[1]) ? true : false;
}

/**
 * This function reads a line from the console and returns an array of integers.
 */
vector<int> readLine(int iterations) {
    vector<int> numbers;
    int number;
    
    for (int i = 1; i <= iterations; i++) {
        if(scanf("%d", &number) != 1) {
            break;
        }
        numbers.push_back(number);
    }

    return numbers;
}

int main() {
    // Read board size and number of parts
    boardSize = readLine(2);
    int nParts = readLine(1)[0];

    if (nParts == 0) {
        printf("%d\n", 0);
        return 0;
    }

    // Initialize the 'calculatedValues' vector with 0 in all the entries.
    for (int lx = 0; lx < boardSize[0]; lx++) {
        vector<int> defaultLine(boardSize[1], 0);
        calculatedValues.push_back(defaultLine);
    }

    int minPartDimension = 0;
    for (int i = 0; i < nParts; i++) {
        vector<int> line = readLine(3);

        int width = line[0] - 1, height = line[1] - 1, price = line[2];

        minPartDimension = (width < minPartDimension || i == 0) ? width : minPartDimension;
        minPartDimension = (height < minPartDimension) ? height : minPartDimension;

        if (isInBounds(width, height)) {
            if (calculatedValues[width][height] < price) {
                calculatedValues[width][height] = price;
            }
        }

        // Check if the part is a square. If not, add a new rotated part with the same value.
        if (width != height) {
            if (isInBounds(height, width)) {
                if (calculatedValues[height][width] < price) {
                    calculatedValues[height][width] = price;
                }
            }
        }
    }

    // At this point, the calculatedValues table will have the best value for each part dimensions.


    // When the NxN entry is filled (max between the initial value and the function) there's no
    // update needed!
    // The final result will be in the last entry of the table!

    for (int lx = minPartDimension; lx < boardSize[0]; lx++) {
        for (int cx = minPartDimension; cx < boardSize[1]; cx++) {
            if (lx > cx && lx < boardSize[1]) {
                calculatedValues[lx][cx] = calculatedValues[cx][lx];
            } else if (lx == cx) {
                int horizontalCut = cut(lx, cx, "horizontal");
                calculatedValues[lx][cx] = horizontalCut;
            } else {
                int horizontalCut = cut(lx, cx, "horizontal");
                int verticalCut = cut(lx, cx, "vertical");
                calculatedValues[lx][cx] = (horizontalCut > verticalCut) ? horizontalCut : verticalCut;
            }
        }
    }  

    printf("%d\n", calculatedValues[boardSize[0] - 1][boardSize[1] - 1]);

    return 0;
}   