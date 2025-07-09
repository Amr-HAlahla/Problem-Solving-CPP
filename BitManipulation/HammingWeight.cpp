#include <iostream>
using namespace std;

// Function to count the number of '1' bits in an unsigned integer
int hammingWeight(int n)
{
    int count = 0;
    while (n != 0)
    {
        count += 1;
        n = n & (n - 1);
    }
    return count;
}

int main()
{
    int n = 29; // Example value
    cout << "Hamming Weight (number of '1' bits) for " << n << ": " << hammingWeight(n) << endl;
    return 0;
}

/*
Time Complexity: O(k), where k is the number of set bits in n. Each iteration clears one set bit.
Space Complexity: O(1), as only a few variables are used.
Explanation: The loop runs once for each '1' bit in n, using n & (n-1) to clear the lowest set bit each time.
*/
