#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);

        if(!head){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int val){
        Node* node = new Node(val);

        if(!tail){
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void deleteNode(Node* node){
        if(!node) return;

        if(node == head) head = node->next;
        if(node == tail) tail = node->prev;

        if(node->prev) node->prev->next = node->next;
        if(node->next) node->next->prev = node->prev;

        delete node;
    }

    void printForward() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void printBackward() {
        Node* curr = tail;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << endl;
    }

};