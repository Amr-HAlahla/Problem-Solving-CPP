#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <limits>
using namespace std;

double maxAverage(vector<int> &nums, int k)
{
    double maxAvg = -std::numeric_limits<double>::infinity();
    double sum = 0.0;

    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }

    maxAvg = sum / k;
    for (int i = k; i < nums.size(); i++)
    {
        sum += nums[i] - nums[i - k];
        maxAvg = std::max(maxAvg, sum / k);
    }

    return maxAvg;
}

int main()
{
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    cout << "Max average of nums1: " << maxAverage(nums1, k1) << endl;

    vector<int> nums2 = {5, 5, 5, 5, 5};
    int k2 = 2;
    cout << "Max average of nums2: " << maxAverage(nums2, k2) << endl;

    vector<int> nums3 = {-1, -12, -5, -6, -50, -3};
    int k3 = 3;
    cout << "Max average of nums3: " << maxAverage(nums3, k3) << endl;

    vector<int> nums4 = {7};
    int k4 = 1;
    cout << "Max average of nums4: " << maxAverage(nums4, k4) << endl;

    return 0;
}
