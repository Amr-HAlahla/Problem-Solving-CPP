#include <iostream>
using namespace std;

// Function to count the number of '1' bits in an unsigned integer
int hammingWeight(int n) {
    int count = 0;
    while (n != 0) {
        count += 1;
        n = n & (n - 1);
    }
    return count;
}

int main() {
    int n = 29; // Example value
    cout << "Hamming Weight (number of '1' bits) for " << n << ": " << hammingWeight(n) << endl;
    return 0;
}
