#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct HeapEntry
{
    int value;
    int arrayIdx;
    int elementIdx;
    HeapEntry(int v, int a, int e) : value(v), arrayIdx(a), elementIdx(e) {}
    bool operator>(HeapEntry &other)
    {
        return value > other.value;
    }
};

vector<int> mergeKSortedArrays(const vector<vector<int>> &arrays)
{
    priority_queue<HeapEntry, vector<HeapEntry>, greater<HeapEntry>> minHeap;
    vector<int> result;
    int k = arrays.size();
    // Initialize heap with first element of each array
    for (int i = 0; i < k; ++i)
    {
        if (!arrays[i].empty())
        {
            minHeap.emplace(arrays[i][0], i, 0);
        }
    }
    while (!minHeap.empty())
    {
        HeapEntry curr = minHeap.top();
        minHeap.pop();
        result.push_back(curr.value);
        int nextIdx = curr.elementIdx + 1;
        if (nextIdx < arrays[curr.arrayIdx].size())
        {
            minHeap.push(HeapEntry(arrays[curr.arrayIdx][nextIdx], curr.arrayIdx, nextIdx));
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> arrays = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}};
    vector<int> merged = mergeKSortedArrays(arrays);
    for (int x : merged)
        cout << x << " "; // 1 1 2 3 4 4 5 6
    cout << endl;
    return 0;
}
