#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b)
{
    unsigned long x = stoul(a, nullptr, 2);
    unsigned long y = stoul(b, nullptr, 2);

    while (y)
    {
        unsigned long without_carry = x ^ y;
        unsigned long carry = (x & y) << 1;
        x = without_carry;
        y = carry;
    }

    string result;
    if (x == 0)
        return "0";
    while (x)
    {
        result = char('0' + (x & 1)) + result;
        x >>= 1;
    }
    return result;
}

int main()
{
    string a = "1011";
    string b = "1101";
    string sum = addBinary(a, b);
    cout << "Sum: " << sum << endl;
    return 0;
}

/*
Time Complexity: O(max(n, m)), where n and m are the lengths of the input strings. Each bit is processed once.
Space Complexity: O(max(n, m)), for the result string.
Explanation: We simulate binary addition, processing each bit from right to left, so the work is linear in the length of the longer string.
*/