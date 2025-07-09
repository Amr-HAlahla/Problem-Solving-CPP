#include <iostream>
#include <vector>
using namespace std;

/*Problem Brief: 
Given an array of integers and a target value, remove all instances of the target value in-place and return the new length of the array. 
The order of elements can be changed, and it doesn't matter what you leave beyond the new length.
*/

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
