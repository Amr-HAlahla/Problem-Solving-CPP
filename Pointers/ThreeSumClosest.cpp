#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// Returns the sum of the triplet in nums that is closest to target
int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int closest = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n - 2; ++i)
    {
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < abs(closest - target))
            {
                closest = sum;
            }
            if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                return sum; // exact match
            }
        }
    }
    return closest;
}

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = threeSumClosest(nums, target);
    cout << "Closest sum: " << result << endl; // Output: 2
    return 0;
}
