#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*Problem: Two Sum All Pairs
Given an array of integers nums and an integer target, return
all unique pairs of indices such that the numbers at those indices add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

vector<vector<int>> twoSumAllPairs(vector<int> &nums, int target)
{
    unordered_map<int, vector<int>> map; // key: number, value: list of indices
    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (map.find(complement) != map.end())
        {
            for (int idx : map[complement])
            {
                result.push_back({idx, i});
            }
        }
        map[nums[i]].push_back(i);
    }
    return result;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15, 7, 2};
    int target = 9;
    vector<vector<int>> pairs = twoSumAllPairs(nums, target);
    for (const auto &pair : pairs)
    {
        cout << pair[0] << " " << pair[1] << endl;
    }
    return 0;
}

/*
result = {
    {0, 1},  // nums[0]=2, nums[1]=7
    {0, 4},  // nums[0]=2, nums[4]=7
    {1, 5},  // nums[1]=7, nums[5]=2
    {4, 5}   // nums[4]=7, nums[5]=2
}
*/