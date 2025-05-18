#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Returns true if s and t are anagrams
bool isAnagram(const string &s, const string &t)
{
    if (s.length() != t.length())
        return false;
    unordered_map<char, int> counts;
    for (char c : s)
        counts[c]++;
    for (char c : t)
    {
        if (counts.find(c) == counts.end() || counts[c] == 0)
            return false;
        counts[c]--;
    }
    return true;
}

int main()
{
    string s1 = "rat", t1 = "tar";
    string s2 = "hello", t2 = "bello";
    cout << (isAnagram(s1, t1) ? "True" : "False") << endl; // True
    cout << (isAnagram(s2, t2) ? "True" : "False") << endl; // False
    return 0;
}
