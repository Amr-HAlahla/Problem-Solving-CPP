#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *current = head;

    while (current != nullptr)
    {
        ListNode *next = current->next; // preserve the next
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head = reverseList(head);
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " "; // 3 2 1
        curr = curr->next;
    }
    return 0;
}