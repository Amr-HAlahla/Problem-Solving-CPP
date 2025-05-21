#include <iostream>
#include <unordered_set>
using namespace std;

// Problem: Determine if a number is a "happy number".
// A happy number is defined as follows:
// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle that does not include 1.
// Numbers for which this process ends in 1 are happy numbers.

bool isHappy(int n)
{
    unordered_set<int> seen;
    while (n != 1)
    {
        if (seen.find(n) != seen.end())
        {
            return false; // Cycle detected
        }
        seen.insert(n);
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
    }
    return true;
}

int main()
{
    int n = 19;
    cout << (isHappy(n) ? "True" : "False") << endl; // True
    return 0;
}