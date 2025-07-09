#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Returns all unique triplets [a, b, c] such that a + b + c == 0
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 2; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue; // skip duplicates
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);
    for (const auto &triplet : res)
    {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

/*
Time Complexity: O(n^2), where n is the number of elements. Sorting is O(n log n), and for each element, we use a two-pointer scan.
Space Complexity: O(|output|), for storing the result triplets.
Explanation: After sorting, for each element, we use two pointers to find pairs, resulting in quadratic time.
*/
