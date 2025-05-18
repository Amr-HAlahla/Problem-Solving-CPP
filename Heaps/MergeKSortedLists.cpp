#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Compare
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val; // Min-heap
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, Compare> minHeap;

    for (ListNode *list : lists)
    {
        if (list)
            minHeap.push(list);
    }

    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (!minHeap.empty())
    {
        ListNode *node = minHeap.top();
        minHeap.pop();
        tail->next = node;
        tail = node;
        if (node->next)
            minHeap.push(node->next);
    }

    return dummy.next;
}

int main()
{
    vector<ListNode *> lists;
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);
    ListNode *result = mergeKLists(lists);
    while (result)
    {
        cout << result->val << " "; // 1 1 2 3 4 4 5 6
        result = result->next;
    }
    cout << endl;
    return 0;
}