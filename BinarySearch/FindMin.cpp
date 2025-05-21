#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
        {
            left = mid + 1; // Minimum in right half
        }
        else
        {
            right = mid; // Minimum in left half or at mid
        }
    }
    return nums[left];
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums) << endl; // 0
    return 0;
}