/*
#include <vector>

using namespace std;

int main() {
    vector<int> parent(10, 0);

    return 0;
}
*/
#include <vector>

int main() {
    std::vector<int> myVector;
    myVector.shrink_to_fit();  // Optionally, you can use 0 to minimize initial capacity
    // ...
    return 0;
}