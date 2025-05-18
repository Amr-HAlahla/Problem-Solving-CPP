#include <iostream>
#include <string>
using namespace std;

// Returns true if s is a subsequence of t
bool isSubsequence(const string &s, const string &t)
{
    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
            i++;
        j++;
    }
    return i == s.size();
}

int main()
{
    string s1 = "ace", t1 = "abcde";
    string s2 = "aec", t2 = "abcde";
    cout << (isSubsequence(s1, t1) ? "True" : "False") << endl; // True
    cout << (isSubsequence(s2, t2) ? "True" : "False") << endl; // False
    return 0;
}
