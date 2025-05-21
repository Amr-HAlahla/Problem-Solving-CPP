#include <iostream>
#include <vector>
using namespace std;

// Returns the maximum sum of any contiguous subarray of size k.
int maxSumSubarray(vector<int> &nums, int k)
{
    if (nums.size() < k)
        return 0;

    int max_sum = 0;
    int window_sum = 0;

    // First window
    for (int i = 0; i < k; i++)
    {
        window_sum += nums[i];
    }
    max_sum = window_sum;

    for (int i = k; i < nums.size(); i++)
    {
        window_sum += nums[i] - nums[i - k];
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

int main()
{
    vector<int> nums = {1, 4, 2, 10, 2, 3, 1};
    int k = 3;
    cout << maxSumSubarray(nums, k) << endl; // 16
    return 0;
}