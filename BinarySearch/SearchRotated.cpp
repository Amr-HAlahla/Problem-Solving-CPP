#include <iostream>
#include <vector>
using namespace std;

/*Problem Statement briefly:
You are given a rotated sorted array and a target value. 
Your task is to find the index of the target value in the array. 
If the target is not found, return -1. The array may contain duplicates.
*/

int search(vector<int> &nums, int target)
{
    // First lets determine the start and the end of the rotated sorted array.
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    
    int pivot = left;
    if (pivot == 0)
    {
        left = 0, right = n - 1;
    }
    else if (target >= nums[0])
    {
        left = 0, right = pivot - 1;
    }
    else
    {
        left = pivot, right = n - 1;
    }

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int main()
{
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Index of 0: " << search(nums1, 0) << endl; // 4
    cout << "Index of 3: " << search(nums1, 3) << endl; // -1
    cout << "Index of 7: " << search(nums1, 7) << endl; // 3
    vector<int> nums2 = {1};
    cout << "Index of 1: " << search(nums2, 1) << endl; // 0
    vector<int> nums3 = {1, 3};
    cout << "Index of 3: " << search(nums3, 3) << endl; // 1
    vector<int> nums4 = {5, 1, 3};
    cout << "Index of 5: " << search(nums4, 5) << endl; // 0
    return 0;
}