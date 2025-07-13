#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int> &nums)
{
    int xorAll = 0;
    int xorNums = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        xorAll ^= i;
    }

    for (int num : nums)
    {
        xorNums ^= num;
    }

    return xorAll ^ xorNums;
}

/* Explanation:
 * xorAll contains XOR of 0 to n
 * xorNums contains XOR of all elements in the array
 * Their XOR gives us the missing number:
 * xorAll ^ xorNums = missing_number
 *
 * Time Complexity:
 * Time: O(n).
 * Space: O(1).
 */