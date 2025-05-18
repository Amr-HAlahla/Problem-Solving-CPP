#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        if (nums[left] == target)
        {
            nums[left] = nums[right];
            right--;
        }
        else
        {
            left++;
        }
    }
    return left;
}

int main()
{
    vector<int> nums = {3, 2, 2, 3, 4, 2, 3};
    int target = 3;
    int newLength = removeElement(nums, target);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
