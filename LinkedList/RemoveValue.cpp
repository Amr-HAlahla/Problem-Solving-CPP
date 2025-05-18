#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *removeByValue(ListNode *head, int value)
{
    // Dummy node to handle head removals
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy, *curr = head;
    while (curr)
    {
        if (curr->val == value)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy.next;
}

// Helper functions for testing
ListNode* createList(const initializer_list<int>& vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int v : vals) {
        if (!head) {
            head = tail = new ListNode(v);
        } else {
            tail->next = new ListNode(v);
            tail = tail->next;
        }
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    ListNode* head = createList({1,2,6,3,6});
    cout << "Original: ";
    printList(head);
    head = removeByValue(head, 6);
    cout << "After removal: ";
    printList(head);
    freeList(head);
    return 0;
}