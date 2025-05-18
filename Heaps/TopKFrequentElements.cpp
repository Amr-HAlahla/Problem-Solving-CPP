#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    for (int num : nums)
        freq[num]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    for (auto &[num, count] : freq)
    {
        minHeap.push({count, num});
        if (minHeap.size() > k)
            minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty())
    {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    for (int x : result)
    {
        cout << x << " "; // 1 2
    }
    cout << endl;
    return 0;
}