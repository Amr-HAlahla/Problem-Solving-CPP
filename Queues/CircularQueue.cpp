#include <iostream>
#include <vector>
using namespace std;

class MyQueue
{
private:
    int rear, front, size, capacity;
    vector<int> queue;

public:
    MyQueue(int c)
    {
        front = 0;
        rear = -1;
        size = 0;
        capacity = c;
        queue = vector<int>(c, 0);
    }

    void enque(int val)
    {
        rear = (rear + 1) % capacity;
        queue[rear] = val;
        size += 1;
    }

    int deque()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Queue is empty");
        }
        int val = queue[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return queue[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return queue[rear];
    }
};

int main()
{
    MyQueue q(5);
    cout << "Enqueue 1, 2, 3" << endl;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    cout << "Front: " << q.getFront() << endl;               // Should be 1
    cout << "Rear: " << q.getRear() << endl;                 // Should be 3
    cout << "Dequeue: " << q.deque() << endl;                // Should be 1
    cout << "Front after dequeue: " << q.getFront() << endl; // Should be 2
    cout << "Is Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is Full: " << (q.isFull() ? "Yes" : "No") << endl;
    q.enque(4);
    q.enque(5);
    q.enque(6); // Now should be full
    cout << "Is Full after adding more: " << (q.isFull() ? "Yes" : "No") << endl;
    cout << "Rear: " << q.getRear() << endl; // Should be 6
    // Dequeue all
    while (!q.isEmpty())
    {
        cout << "Dequeue: " << q.deque() << endl;
    }
    cout << "Is Empty at end: " << (q.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}

/*
Time Complexity: O(1) for all operations (enqueue, dequeue, isEmpty, isFull).
Space Complexity: O(n), where n is the capacity of the queue.
Explanation: All operations are performed with direct index calculations, so they are constant time.
*/
