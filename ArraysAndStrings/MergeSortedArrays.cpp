#include <iostream>
#include <vector>
using namespace std;

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
