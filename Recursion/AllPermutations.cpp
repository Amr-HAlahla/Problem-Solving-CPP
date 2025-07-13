#include <vector>
#include <iostream>
using namespace std;

void backtrack(vector<int> &nums, int start, vector<vector<int>> &result)
{
    if (start == nums.size())
    {
        result.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++)
    {
        swap(nums[start], nums[i]);         // chose
        backtrack(nums, start + 1, result); // explore
        swap(nums[start], nums[i]);         // undo
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    backtrack(nums, 0, result);
    return result;
}

// Time Complexit = (n!), since all permutations are explored!