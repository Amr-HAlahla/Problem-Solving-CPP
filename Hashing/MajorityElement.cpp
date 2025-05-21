#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the majority element (appears more than n/2 times)
int majorityElement(const vector<int> &nums)
{
    int count = 0, answer = -1;

    for (int num : nums)
    {
        if (count == 0)
            answer = num;
        if (answer == num)
            count += 1;
        else
            count -= 1;
    }
    return answer;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = majorityElement(nums);
    if (result != -1)
        cout << "Majority element: " << result << endl;
    else
        cout << "No majority element found." << endl;
    return 0;
}