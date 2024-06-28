#include <iostream>
#include <cmath>

using namespace std;

int nLevels = 12;

void buildTree(int origin) {
    int left = 2*origin + 1;
    int right = left + 1;

    printf("%d %d\n", origin, left);
    printf("%d %d\n", origin, right);
}

void build() {
    for (int level = 0; level <= nLevels; level++) {
        int origin = pow(2, level) - 1;
        if (level == 0) origin = 0;

        int lastOrigin = pow(2, level + 1) - 2;

        while(origin <= lastOrigin) {
            buildTree(origin);
            origin++;
        }
    }
}

int main() {
    int lastLineNVertices = pow(2, nLevels + 1) - 2;
    int lastVertice = lastLineNVertices * 2 + 2;

    printf("%d %d\n", lastVertice, lastVertice);

    build();

    return 0;
}