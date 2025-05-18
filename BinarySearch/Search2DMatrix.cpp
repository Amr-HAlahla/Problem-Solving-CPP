#include <iostream>
#include <vector>
using namespace std;

// LeetCode 74: Search a 2D Matrix
// Each row is sorted left to right, and the first integer of each row is greater than the last integer of the previous row.

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
        return false;
    int rows = matrix.size(), cols = matrix[0].size();
    int left = 0, right = rows * cols - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int midVal = matrix[mid / cols][mid % cols];
        if (midVal == target)
            return true;
        else if (midVal < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    cout << boolalpha;
    cout << "Search 3: " << searchMatrix(matrix, 3) << endl;     // true
    cout << "Search 13: " << searchMatrix(matrix, 13) << endl;   // false
    cout << "Search 60: " << searchMatrix(matrix, 60) << endl;   // true
    cout << "Search 1: " << searchMatrix(matrix, 1) << endl;     // true
    cout << "Search 100: " << searchMatrix(matrix, 100) << endl; // false
    return 0;
}
