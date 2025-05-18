#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int minSubArray(vector<int> &nums, int target)
{
    int minLength = std::numeric_limits<int>::max();
    int sum = 0, left = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];
        // Verify window
        while (sum >= target && left <= right)
        {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return (minLength == std::numeric_limits<int>::max()) ? 0 : minLength;
}

int main()
{
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;
    cout << "Example 1: " << minSubArray(nums1, target1) << endl; // Output: 2

    vector<int> nums2 = {1, 4, 4};
    int target2 = 4;
    cout << "Example 2: " << minSubArray(nums2, target2) << endl; // Output: 1

    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    int target3 = 11;
    cout << "Example 3: " << minSubArray(nums3, target3) << endl; // Output: 0

    return 0;
}