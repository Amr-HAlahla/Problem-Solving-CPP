#include <iostream>
using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEnd = false;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (node->children[index] == nullptr)
            {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (node->children[index] == nullptr)
            {
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char c : prefix)
        {
            int index = c - 'a';
            if (node->children[index] == nullptr)
                return false;
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    cout << (trie.search("apple") ? "True" : "False") << endl;   // True
    cout << (trie.search("app") ? "True" : "False") << endl;     // False
    cout << (trie.startsWith("app") ? "True" : "False") << endl; // True
    trie.insert("app");
    cout << (trie.search("app") ? "True" : "False") << endl; // True
    return 0;
}