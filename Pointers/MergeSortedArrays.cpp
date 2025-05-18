#include <iostream>
#include <vector>
using namespace std;

void mergeInPlace(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p1 = m - 1;    // Pointer for nums1
    int p2 = n - 1;    // Pointer for nums2
    int p = m + n - 1; // Pointer for merged array
    while (p2 >= 0 && p1 >= 0)
    {
        if (nums1[p1] > nums2[p2])
        {
            nums1[p] = nums1[p1];
            p1--;
        }
        else
        {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
    while (p2 >= 0)
    {
        nums1[p] = nums2[p2];
        p--;
        p2--;
    }
}

// Merges two sorted arrays into a new sorted array (not in-place)
vector<int> mergeToNewArray(const vector<int> &nums1, int m, const vector<int> &nums2, int n)
{
    vector<int> result;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
            result.push_back(nums1[i++]);
        else
            result.push_back(nums2[j++]);
    }
    while (i < m)
        result.push_back(nums1[i++]);
    while (j < n)
        result.push_back(nums2[j++]);
    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    mergeInPlace(nums1, m, nums2, n);
    for (int x : nums1)
        cout << x << " "; // 1 2 2 3 5 6
    cout << endl;

    // Demonstrate merge to new array
    vector<int> nums1b = {1, 2, 3};
    vector<int> nums2b = {2, 5, 6};
    vector<int> merged = mergeToNewArray(nums1b, nums1b.size(), nums2b, nums2b.size());
    for (int x : merged)
        cout << x << " "; // 1 2 2 3 5 6
    cout << endl;

    return 0;
}