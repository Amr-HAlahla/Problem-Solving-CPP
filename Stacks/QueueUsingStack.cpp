#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> inQueue;
    stack<int> outQueue;

public:
    void enque(int value)
    {
        inQueue.push(value);
    }

    int deque()
    {
        if (outQueue.empty() && !inQueue.empty())
        {
            while (!inQueue.empty())
            {
                outQueue.push(inQueue.top());
                inQueue.pop();
            }
        }
        if (outQueue.empty())
        {
            return -1;
        }

        int result = outQueue.top();
        outQueue.pop();
        return result;
    }
};

int main()
{
    Queue q;
    q.enque(10);
    q.enque(20);
    q.enque(30);

    cout << q.deque() << endl; // Output: 10
    cout << q.deque() << endl; // Output: 20
    q.enque(40);
    cout << q.deque() << endl; // Output: 30
    cout << q.deque() << endl; // Output: 40
    cout << q.deque() << endl; // Output: -1 (queue is empty)

    return 0;
}
