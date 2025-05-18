/*
Problem: Given tasks and a cooldown period n,
find the least time to complete all tasks (e.g., tasks=['A','A','A','B','B','B'], n=2 → 8).
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, int> freq;
    for (char task : tasks)
        freq[task]++;

    priority_queue<int> maxHeap;
    for (auto &[task, count] : freq)
        maxHeap.push(count);

    int time = 0;
    queue<pair<int, int>> cooldown; // {count, available time}
    while (!maxHeap.empty() || !cooldown.empty())
    {
        time++;
        if (!maxHeap.empty())
        {
            int count = maxHeap.top() - 1;
            maxHeap.pop();
            if (count > 0)
                cooldown.push({count, time + n});
        }
        if (!cooldown.empty() && cooldown.front().second == time)
        {
            maxHeap.push(cooldown.front().first);
            cooldown.pop();
        }
    }
    return time;
}

int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << leastInterval(tasks, n) << endl; // 8
    return 0;
}