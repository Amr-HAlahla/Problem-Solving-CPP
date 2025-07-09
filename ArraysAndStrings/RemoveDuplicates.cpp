#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Remove Duplicates from Sorted Array
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int write = 1;
    for (int read = 1; read < nums.size(); read++)
    {
        if (nums[read - 1] != nums[read])
        {
            nums[write] = nums[read];
            write++;
        }
    }
    return write;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3};
    int len = removeDuplicates(nums);
    for (int i = 0; i < len; i++)
    {
        cout << nums[i] << " "; // 1 2 3
    }
    return 0;
}