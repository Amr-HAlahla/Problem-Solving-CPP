#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> uniqueTriplets;
    int n = nums.size();

    for (int i = 0; i < n - 2; ++i)
    {
        unordered_set<int> seen;
        for (int j = i + 1; j < n; ++j)
        {
            int complement = -(nums[i] + nums[j]);
            if (seen.count(complement))
            {
                vector<int> triplet = {nums[i], nums[j], complement};
                sort(triplet.begin(), triplet.end()); // sort only the triplet to avoid duplicates
                uniqueTriplets.insert(triplet);
            }
            seen.insert(nums[j]);
        }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}

// Time complexity: O(n^2) => The outer loop runs n times, and the inner loop runs at most n times.
// Space complexity: O(n)
