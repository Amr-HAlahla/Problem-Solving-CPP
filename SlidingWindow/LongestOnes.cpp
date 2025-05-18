#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// up to k zero replacements allowed
int longestOnes(vector<int> &nums, int k)
{
    int maxLen = 0, left = 0, zeroCount = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] == 0)
            zeroCount++;
        while (zeroCount > k)
        {
            if (nums[left] == 0)
                zeroCount--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main()
{
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    cout << "Test 1: " << longestOnes(nums1, k1) << endl; // Expected: 6

    vector<int> nums2 = {0, 0, 1, 1, 1, 0, 0};
    int k2 = 0;
    cout << "Test 2: " << longestOnes(nums2, k2) << endl; // Expected: 3

    vector<int> nums3 = {1, 1, 1, 1};
    int k3 = 2;
    cout << "Test 3: " << longestOnes(nums3, k3) << endl; // Expected: 4

    vector<int> nums4 = {0, 0, 0, 0};
    int k4 = 2;
    cout << "Test 4: " << longestOnes(nums4, k4) << endl; // Expected: 2

    return 0;
}
