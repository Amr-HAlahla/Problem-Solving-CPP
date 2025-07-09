#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * Problem: Longest Consecutive Sequence
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * Example: [100, 4, 200, 1, 3, 2] -> Output: 4 (the longest consecutive sequence is [1, 2, 3, 4])
 */

int longestConsecutive(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;
    for (int num : numSet)
    {
        // if n-1 does not exist, then this could be a start of a consecutive streak.
        if (numSet.find(num - 1) == numSet.end())
        {
            int current_streak = 1;
            while (numSet.find(num + 1) != numSet.end())
            {
                current_streak++;
                num++;
            }
            longest = max(longest, current_streak);
        }
    }
    return longest;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl; // Output: 4
    return 0;
}