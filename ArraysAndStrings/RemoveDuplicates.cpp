#include <iostream>
#include <vector>
using namespace std;

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