#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Problem: Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

// returns vector for dynamic list.
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map; // key: number, value: index

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (map.find(complement) != map.end())
        {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl; // 0 1
    return 0;
}