#include <unordered_map>
using namespace std;


/*
* Problem Statement
* Implement an LRU Cache class with the following interface:

class LRUCache {
public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
};

*/

/* Requirements
* get(key) — return value if exists, else -1.
* put(key, value) — insert/update key. If capacity is full, evict the least recently used item.
* Time Complexity: O(1) for both get and put.
*/

/* Solution Idea
* 2- Doubly Linked List to maintain access order.
* 1- Hash Map to map keys to their node in the list.
*/

struct Node {
    int key, value;
    Node *prev, *next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node *head, *tail;
    int cap;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0); // dummy head
        tail = new Node(0, 0); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            node->value = value;
            remove(node);
            insert(node);
        } else {
            if (cache.size() == cap) {
                Node* lru = tail->prev;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            cache[key] = node;
            insert(node);
        }
    }
};
