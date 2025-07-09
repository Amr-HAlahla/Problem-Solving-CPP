#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        return;

    grid[i][j] = '0'; // mark as visited
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
}

int numIslands(vector<vector<char>> &grid)
{
    if (grid.empty())
        return 0;

    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> grid = {{'1', '1', '0'}, {'1', '1', '0'}, {'0', '0', '1'}};
    cout << numIslands(grid) << endl; // 2
    return 0;
}

/*
Time Complexity: O(m * n), where m and n are the dimensions of the grid. Each cell is visited once.
Space Complexity: O(m * n) in the worst case for the recursion stack (all land).
Explanation: We perform DFS from each unvisited land cell, marking all connected land, so each cell is processed once.
*/