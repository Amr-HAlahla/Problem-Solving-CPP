#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> &heights)
{
    int left = 0, right = heights.size();
    int maxArea = 0;
    while (left < right)
    {
        int width = right - left;
        int h = min(heights[left], heights[right]);

        int area = width * h;
        maxArea = max(maxArea, area);

        if (heights[left] > heights[right])
            right--;
        else
            left++;
    }
    return maxArea;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl; // 49
    return 0;
}