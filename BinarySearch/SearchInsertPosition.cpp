#include <iostream>
#include <vector>
using namespace std;

/**
 * Problem: Search Insert Position
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * Example: nums = [1, 3, 5, 6], target = 5 -> Output: 2
 * Example: nums = [1, 3, 5, 6], target = 2 -> Output: 1
 * Example: nums = [1, 3, 5, 6], target = 7 -> Output: 4
 */

int searchInsert(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    cout << searchInsert(nums, target) << endl; // 4
    return 0;
}