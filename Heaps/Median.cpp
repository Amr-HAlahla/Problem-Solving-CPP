#include <iostream>
#include <queue>
using namespace std;

/*
max-heap for the lower half of numbers (all values ≤ median).
min-heap for the upper half of numbers (all values ≥ median).
Keep heaps balanced (sizes equal or differ by 1) to ensure the median is at the top of one or both heaps.
*/

class MedianFinder
{
private:
    priority_queue<int> maxHeap;                            // Lower half (max-heap)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Upper half (min-heap)
public:
    void addNum(int num)
    {
        // Step 1: Add to appropriate heap
        if (maxHeap.empty() || num < maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        // Step 2: Balance heaps
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        // Step 3: Compute median
        if (maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

int main()
{
    MedianFinder mf;
    mf.addNum(1);
    cout << mf.findMedian() << endl; // 1
    mf.addNum(3);
    cout << mf.findMedian() << endl; // 2
    mf.addNum(2);
    cout << mf.findMedian() << endl; // 2
    return 0;
}