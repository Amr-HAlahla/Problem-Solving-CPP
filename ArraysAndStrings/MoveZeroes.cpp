#include <iostream>
#include <vector>
using namespace std;

/*
Pproblem: Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the
relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
*/

void moveZeroes(vector<int> &nums)
{
    int write = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[write] = nums[i];
            write++;
        }
    }

    while (write < nums.size())
    {
        nums[write] = 0;
        write++;
    }
}

int main()
{
    vector<int> nums = {1, 0, 0, 2, 3, 0, 7};
    moveZeroes(nums);
    for (int x : nums)
    {
        cout << x << " "; // 1 2 3 7 0 0 0
    }
    return 0;
}
/*
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */