#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * Problem: Is Anagram
 * Given two strings, determine if one is an anagram of the other.
 * An anagram is a word formed by rearranging the letters of another.
 * Example: "rat" and "tar" are anagrams, while "hello" and "bello" are not.
 */

bool isAnagram(string &s, string &t)
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

bool isAnagram2(const string &s, const string &t)
{
    if (s.length() != t.length())
        return false;

    unordered_map<char, int> counts;
    for (char c : s)
        counts[c]++;
    for (char c : t)
        counts[c]--;
    for (const auto &pair : counts)
        if (pair.second != 0)
            return false;
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