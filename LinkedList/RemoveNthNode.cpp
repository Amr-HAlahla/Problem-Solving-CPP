#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode dummy(0);
    dummy.next = head;

    ListNode *slow = &dummy;
    ListNode *fast = &dummy;

    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }

    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy.next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = removeNthFromEnd(head, 2);
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " "; // 1 2 3 5
        curr = curr->next;
    }
    return 0;
}