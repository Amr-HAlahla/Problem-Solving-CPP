#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Queue
{
private:
    ListNode *front;
    ListNode *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    void enqueue(int x)
    {
        ListNode *node = new ListNode(x);
        if (rear == nullptr)
        {
            front = rear = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Queue is empty");
        }
        ListNode *temp = front;
        int val = temp->val;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        return val;
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    int peek() const
    {
        if (isEmpty())
        {
            throw std::out_of_range("Queue is empty");
        }
        return front->val;
    }
};
