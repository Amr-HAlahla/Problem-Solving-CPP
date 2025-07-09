#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }

    return false;
}
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main()
{
    // Create a list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // No cycle
    cout << "Has cycle (should be 0): " << hasCycle(head) << endl;
    cout << "Cycle entry (should be 0x0): " << detectCycle(head) << endl;

    // Create a cycle: 5 -> 3
    head->next->next->next->next->next = head->next->next; // 5->3

    cout << "Has cycle (should be 1): " << hasCycle(head) << endl;
    ListNode *entry = detectCycle(head);
    cout << "Cycle entry value (should be 3): " << (entry ? entry->val : -1) << endl;

    // Clean up (avoid memory leak, but beware of cycle)
    head->next->next->next->next->next = nullptr;
    ListNode *curr = head;
    while (curr)
    {
        ListNode *next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}

/*
Time Complexity: O(n), where n is the number of nodes. Each pointer traverses the list at most twice.
Space Complexity: O(1), as only two pointers are used.
Explanation: Floyd's Tortoise and Hare algorithm uses two pointers moving at different speeds to detect a cycle in linear time and constant space.
*/