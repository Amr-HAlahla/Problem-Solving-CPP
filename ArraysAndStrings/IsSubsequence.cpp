#include <iostream>
#include <string>
using namespace std;

/* * Function to check if string s is a subsequence of string t.
 * A string s is a subsequence of string t if you can remove some characters from t
 * (possibly none) to get s.
 */
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

/*
Time Complexity: O(n), where n is the length of t. We scan through t once, and at most through s once.
Space Complexity: O(1), as we use only a constant amount of extra space.
Explanation: We use two pointers to traverse both strings. Each pointer only moves forward, so the total work is linear in the size of t.
*/
