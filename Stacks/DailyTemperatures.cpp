#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && temperatures[i] > temperatures[s.top()])
        {
            result[s.top()] = i - s.top();
            s.pop();
        }

        s.push(i);
    }

    return result;
}

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);
    for (int x : result)
    {
        cout << x << " "; // 1 1 4 2 1 1 0 0
    }
    return 0;
}