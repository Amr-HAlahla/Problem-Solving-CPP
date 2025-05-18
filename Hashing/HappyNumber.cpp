#include <iostream>
#include <unordered_set>
using namespace std;

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