#include <iostream>
#include <vector>
using namespace std;

// Returns an array output such that output[i] is the product of all elements of nums except nums[i]
vector<int> productExceptSelf(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> output(n, 1);
    int left = 1;
    for (int i = 0; i < n; i++)
    {
        output[i] = left;
        left *= nums[i];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        output[i] *= right;
        right *= nums[i];
    }
    return output;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);
    for (int x : result)
    {
        cout << x << " "; // Output: 24 12 8 6
    }
    cout << endl;
    return 0;
}
