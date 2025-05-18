#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> values;
    stack<int> mins;
    stack<int> maxs; // Stack to keep track of maximums

public:
    void push(int val)
    {
        values.push(val);
        if (mins.empty() || val <= mins.top())
            mins.push(val);
        if (maxs.empty() || val >= maxs.top())
            maxs.push(val);
    }

    void pop()
    {
        if (!values.empty())
        {
            if (values.top() == mins.top())
                mins.pop();
            if (values.top() == maxs.top())
                maxs.pop();
            values.pop();
        }
    }

    int top()
    {
        if (!values.empty())
            return values.top();
        return -1;
    }

    int getMin()
    {
        if (!mins.empty())
            return mins.top();
        return -1;
    }

    int getMax()
    {
        if (!maxs.empty())
            return maxs.top();
        return -1;
    }
};

int main()
{
    MinStack ms;
    ms.push(3);
    ms.push(5);
    ms.push(2);
    ms.push(1);
    cout << ms.getMin() << endl; // 1
    cout << ms.getMax() << endl; // 5
    ms.pop();
    cout << ms.getMin() << endl; // 2
    cout << ms.getMax() << endl; // 5
    cout << ms.top() << endl;    // 2
    ms.pop();
    cout << ms.getMax() << endl; // 5
    ms.pop();
    cout << ms.getMax() << endl; // 3
    return 0;
}