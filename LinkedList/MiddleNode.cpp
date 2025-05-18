#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *mid = middleNode(head);
    if (mid)
        cout << "Middle node value: " << mid->val << endl; // Output: 3

    // For even number of nodes: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    head->next->next->next->next->next = new ListNode(6);
    mid = middleNode(head);
    if (mid)
        cout << "Middle node value (even): " << mid->val << endl; // Output: 4

    // Clean up
    ListNode *curr = head;
    while (curr)
    {
        ListNode *next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}