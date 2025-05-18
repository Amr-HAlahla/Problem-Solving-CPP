#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum element in a rotated sorted array
int findMax(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        // If mid element is greater than right, max is in right half or at mid
        if (nums[mid] > nums[right])
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
        // To avoid infinite loop when left and mid are adjacent
        if (left == right - 1)
        {
            return max(nums[left], nums[right]);
        }
    }
    return nums[left];
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findMax(nums) << endl; // 7
    vector<int> nums2 = {2, 3, 4, 5, 1};
    cout << findMax(nums2) << endl; // 5
    vector<int> nums3 = {1};
    cout << findMax(nums3) << endl; // 1
    return 0;
}
