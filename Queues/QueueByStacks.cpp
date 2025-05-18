#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> stackIn;
    stack<int> stackOut;

public:
    bool isEmpty()
    {
        return stackIn.empty() && stackOut.empty();
    }

    void enque(int val)
    {
        stackIn.push(val);
    }

    int deque()
    {
        if (isEmpty())
            return -1;

        if (stackOut.empty())
        {
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int val = stackOut.top();
        stackOut.pop();
        return val;
    }
};

int main()
{
    MyQueue q;
    cout << "Enqueue 1, 2, 3" << endl;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    cout << "Dequeue: " << q.deque() << endl; // Should be 1
    cout << "Dequeue: " << q.deque() << endl; // Should be 2
    cout << "Is Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    q.enque(4);
    cout << "Dequeue: " << q.deque() << endl; // Should be 3
    cout << "Dequeue: " << q.deque() << endl; // Should be 4
    cout << "Is Empty at end: " << (q.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}