#include <iostream>
#include <vector>
using namespace std;

/*
Brief Description of the Problem:
You are given two sorted arrays, nums1 and nums2, where nums1 has a size of m + n,
with the first m elements being the valid part of nums1 and the last n elements initialized to 0.
The task is to merge nums2 into nums1 in sorted order.
*/

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;     // Last element in nums1's valid part
    int j = n - 1;     // Last element in nums2
    int k = m + n - 1; // Last position in nums1

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0)
    {
        nums1[k] = nums2[j];
        k--;
        j--;
    }
}

// Example usage
int main()
{
    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

/*
Time Complexity: O(m + n), where m and n are the lengths of the two arrays. Each element is considered once.
Space Complexity: O(1), as the merge is done in-place in nums1.
Explanation: We fill nums1 from the back, comparing the largest elements, so no extra space is needed and each step is constant time.
*/
