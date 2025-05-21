#include <iostream>
#include <vector>
using namespace std;

// Returns the length of the longest contiguous subarray with sum <= k using sliding window.
int maxSubarrayLength(vector<int> &nums, int k)
{
    int maxLen = 0, windowSum = 0, left = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        windowSum += nums[right]; // Expand window

        while (windowSum > k && left <= right)
        {
            windowSum -= nums[left]; // Shrink window
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;
    cout << maxSubarrayLength(nums, k) << endl; // 4
    return 0;
}