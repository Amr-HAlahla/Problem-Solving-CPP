#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums)
    {
        minHeap.push(num);
        if (minHeap.size() > k)
        {
            minHeap.pop(); // Remove smallest
        }
    }
    return minHeap.top();
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargest(nums, k) << endl; // 5
    return 0;
}

/*
Time Complexity: O(n log k), where n is the number of elements. Each insertion and removal from the heap is O(log k).
Space Complexity: O(k), for the min-heap storing k elements.
Explanation: We maintain a heap of size k, so each operation is logarithmic in k, and we process all n elements.
*/