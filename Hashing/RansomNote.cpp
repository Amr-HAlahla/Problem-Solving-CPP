#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> counts;
    for (char c : magazine)
    {
        counts[c]++;
    }

    for (char c : ransomNote)
    {
        if (counts.find(c) == counts.end() || counts[c] == 0)
        {
            return false;
        }
        counts[c]--;
    }

    return true;
}

int main()
{
    string ransomNote = "aa";
    string magazine = "aab";
    cout << (canConstruct(ransomNote, magazine) ? "True" : "False") << endl; // True
    return 0;
}