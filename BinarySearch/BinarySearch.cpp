#include <iostream>
#include <vector>
using namespace std;

// Iterative binary search
int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Recursive (backtracking) binary search
int searchRecursive(vector<int> &nums, int left, int right, int target)
{
    if (left > right)
        return -1;
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
        return searchRecursive(nums, mid + 1, right, target);
    else
        return searchRecursive(nums, left, mid - 1, target);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 3;
    cout << search(nums, target) << endl;                              // 2
    cout << searchRecursive(nums, 0, nums.size() - 1, target) << endl; // 2
    return 0;
}

/*
Time Complexity: O(log n), where n is the number of elements in the array. Each step halves the search space.
Space Complexity: O(1) for iterative, O(log n) for recursive due to call stack.
Explanation: Binary search repeatedly divides the array in half, so the number of steps is logarithmic.
*/