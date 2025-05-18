#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Shortest subarray with sum at least k.
int shortestSubArray(vector<int> &nums, int k)
{
    int shortest = INT_MAX, sum = 0, left = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];
        // Validate window
        while (sum >= k && left <= right)
        {
            shortest = min(shortest, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return (shortest == INT_MAX) ? -1 : shortest;
}

int main()
{
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int k1 = 7;
    cout << "Shortest subarray length (should be 2): " << shortestSubArray(nums1, k1) << endl;

    vector<int> nums2 = {1, 1, 1, 1, 1, 1, 1};
    int k2 = 11;
    cout << "Shortest subarray length (should be -1): " << shortestSubArray(nums2, k2) << endl;

    vector<int> nums3 = {1, 4, 4};
    int k3 = 4;
    cout << "Shortest subarray length (should be 1): " << shortestSubArray(nums3, k3) << endl;

    return 0;
}