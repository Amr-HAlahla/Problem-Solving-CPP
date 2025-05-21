#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to compute GCD of two numbers
int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to insert GCD nodes between every pair of nodes
ListNode* insertGCD(ListNode* head) {
    ListNode* curr = head;
    while (curr && curr->next) {
        int g = gcd(curr->val, curr->next->val);
        ListNode* node = new ListNode(g);
        node->next = curr->next;
        curr->next = node;
        curr = node->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Creating linked list: 18 -> 24 -> 30
    ListNode* head = new ListNode(18);
    head->next = new ListNode(24);
    head->next->next = new ListNode(30);

    cout << "Original List: ";
    printList(head);

    head = insertGCD(head);

    cout << "After Inserting GCDs: ";
    printList(head);

    // Free memory
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
}