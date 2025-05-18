#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int>> KClosest(vector<vector<int>> &points, int k)
{
    // Max-Heap using pair<distance, point>
    priority_queue<pair<int, vector<int>>> maxHeap;

    for (auto &point : points)
    {
        int x = point[0], y = point[1];
        int dist = x * x + y * y;
        maxHeap.push({dist, point});
        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    vector<vector<int>> result;
    while (!maxHeap.empty())
    {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return result;
}

void printPoints(vector<vector<int>> &points)
{
    for (auto &point : points)
    {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;
}

int main()
{

    vector<vector<int>> points1 = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k1 = 2;

    cout << "Test Case 1:\nInput Points: ";
    printPoints(points1);
    cout << "K = " << k1 << "\nClosest Points: ";
    vector<vector<int>> result1 = KClosest(points1, k1);
    printPoints(result1);

    // Another test case
    vector<vector<int>> points2 = {{3, 3}, {5, -1}, {-2, 4}};
    int k2 = 2;

    cout << "\nTest Case 2:\nInput Points: ";
    printPoints(points2);
    cout << "K = " << k2 << "\nClosest Points: ";
    vector<vector<int>> result2 = KClosest(points2, k2);
    printPoints(result2);

    return 0;
}