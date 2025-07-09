#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem Statement:
Given a collection of intervals, merge all overlapping intervals.
For example, given intervals [1,3], [2,6], [8,10], [15,18],
the merged intervals would be [1,6], [8,10], [15,18].
*/

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};

    // Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i][0] <= merged.back()[1])
        {
            // Overlapping intervals, merge them
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
        else
        {
            // No overlap, add to result
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = merge(intervals);

    cout << "Merged intervals: ";
    for (const auto &interval : result)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}

/*
Time Complexity: O(n log n), where n is the number of intervals. Sorting dominates the runtime, merging is O(n).
Space Complexity: O(n), for storing the merged intervals.
Explanation: We sort the intervals, then iterate through them once to merge, so the main cost is sorting.
*/