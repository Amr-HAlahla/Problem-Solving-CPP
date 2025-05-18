#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Copy the functions from LargestIsland.cpp
int dfs(vector<vector<char>> &grid, int i, int j)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        return 0;

    grid[i][j] = '0'; // mark as visited
    return 1 +
           +dfs(grid, i, j + 1) + dfs(grid, i, j - 1) + dfs(grid, i + 1, j) + dfs(grid, i - 1, j);
}

int largestIslands(vector<vector<char>> &grid)
{
    if (grid.empty())
        return 0;

    int largest = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                largest = max(largest, dfs(grid, i, j));
            }
        }
    }
    return largest;
}

void test1()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    assert(largestIslands(grid) == 4); // The largest island has 4 cells
}

void test2()
{
    vector<vector<char>> grid = {
        {'1', '0', '1', '0'},
        {'0', '1', '0', '1'},
        {'1', '0', '1', '0'},
        {'0', '1', '0', '1'}};
    assert(largestIslands(grid) == 1); // All islands are single cells
}

void test3()
{
    vector<vector<char>> grid = {
        {'0', '0', '0'},
        {'0', '0', '0'},
        {'0', '0', '0'}};
    assert(largestIslands(grid) == 0); // No islands
}

void test4()
{
    vector<vector<char>> grid = {
        {'1', '1', '1'},
        {'1', '1', '1'},
        {'1', '1', '1'}};
    assert(largestIslands(grid) == 9); // One big island
}

void test5()
{
    vector<vector<char>> grid = {};
    assert(largestIslands(grid) == 0); // Empty grid
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    cout << "All tests passed!" << endl;
    return 0;
}