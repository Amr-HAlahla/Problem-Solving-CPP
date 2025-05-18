#include <iostream>
#include <vector>
using namespace std;

bool isPerfectSquare(int num)
{
    int left = 0, right = num;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid * mid == num)
            return true;
        else if (mid * mid > num)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

int main()
{
    vector<int> testCases = {1, 4, 9, 16, 25, 26, 0, 2147395600};
    for (int n : testCases)
    {
        cout << n << (isPerfectSquare(n) ? ": Perfect Square" : ": Not Perfect Square") << endl;
    }
    return 0;
}