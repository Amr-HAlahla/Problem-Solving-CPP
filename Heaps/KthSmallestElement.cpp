#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthSmallest(vector<int> &nums, int k)
{
    priority_queue<int> maxHeap;
    for (int num : nums)
    {
        maxHeap.push(num);
        if (maxHeap.size() > k)
        {
            maxHeap.pop(); // Remove largest
        }
    }
    return maxHeap.top();
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthSmallest(nums, k) << endl; // 2
    return 0;
}