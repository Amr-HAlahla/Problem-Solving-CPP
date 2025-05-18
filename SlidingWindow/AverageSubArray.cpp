#include <iostream>
#include <vector>
using namespace std;

vector<double> averageOfSubarrays(vector<int> &nums, int k)
{
    vector<double> result;
    if (nums.size() < k || k <= 0)
        return result;

    double window_sum = 0;
    for (int i = 0; i < k; i++)
    {
        window_sum += nums[i];
    }
    result.push_back(window_sum / k);

    for (int i = k; i < nums.size(); i++)
    {
        window_sum += nums[i] - nums[i - k];
        result.push_back(window_sum / k);
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 4, 2, 10, 2, 3, 1};
    int k = 3;
    vector<double> averages = averageOfSubarrays(nums, k);
    cout << "Averages of all subarrays of size " << k << ": ";
    for (double avg : averages)
        cout << avg << " ";
    cout << endl;
    return 0;
}
