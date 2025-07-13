#include <vector>
#include <iostream>
using namespace std;

void backtrack(vector<int> &nums, int start, vector<int> &current, vector<vector<int>> &result)
{
    result.push_back(current); // every path is valid
    for (int i = start; i < nums.size(); i++)
    {
        current.push_back(nums[i]);              // choose
        backtrack(nums, i + 1, current, result); // explore
        current.pop_back();                      // undo
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, 0, current, result);
    return result;
}

// Time complexity: O(2^n)