#include <iostream>
using namespace std;
void towerOfHanoi(int n, char source, char destination, char help) {
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, source, help, destination);
    cout << "Move disk "<< "from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, help, destination, source);
}
int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'B', 'C'); // A, B, and C are names of the pegs
    return 0;
}
