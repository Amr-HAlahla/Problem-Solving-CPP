#include <iostream>
#include <vector>
using namespace std;

// Implement this function:
vector<int> sortedSquares(const vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    vector<int> res(nums.size());

    int pos = nums.size() - 1;
    while (left <= right)
    {
        if (abs(nums[left]) > abs(nums[right]))
        {
            res[pos] = nums[left] * nums[left];
            left++;
        }
        else
        {
            res[pos] = nums[right] * nums[right];
            right--;
        }
        pos--;
    }

    return res;
}

int main()
{
    vector<int> nums = {-7, -3, 2, 3, 11};
    vector<int> result = sortedSquares(nums);
    for (int x : result)
        cout << x << " ";
    cout << endl;
    return 0;
}
