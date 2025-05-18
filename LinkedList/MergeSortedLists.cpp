#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode dummy(0); // Dummy node
    ListNode *tail = &dummy;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != nullptr)
        tail->next = l1;
    if (l2 != nullptr)
        tail->next = l2;

    return dummy.next;
}

int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);
    ListNode *merged = mergeTwoLists(l1, l2);
    ListNode *curr = merged;
    while (curr != nullptr)
    {
        cout << curr->val << " "; // 1 2 3 4 5 6
        curr = curr->next;
    }
    return 0;
}