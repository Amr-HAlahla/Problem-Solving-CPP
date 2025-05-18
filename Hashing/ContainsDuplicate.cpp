#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Returns true if any value appears at least twice in the array
bool containsDuplicate(const vector<int> &nums)
{
    unordered_set<int> seen;
    for (int num : nums)
    {
        if (seen.count(num))
            return true;
        seen.insert(num);
    }
    return false;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {1, 2, 3, 1};
    cout << (containsDuplicate(nums1) ? "True" : "False") << endl; // False
    cout << (containsDuplicate(nums2) ? "True" : "False") << endl; // True
    return 0;
}
