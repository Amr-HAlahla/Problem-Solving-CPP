#include <iostream>
#include <vector>
using namespace std;

/* Problem: Given an array of integers nums and an integer k, find the length of the longest subarray
 * such that the sum of its elements is less than or equal to k.
 * The order of elements does not matter.
 */
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
    cout << maxSubarrayLength(nums, k) << endl; // 4 (subarray: [1, -1, 5, -2])
    return 0;
}