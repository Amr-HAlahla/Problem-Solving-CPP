#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * Finds the smallest substring in 's' containing all characters of 't' using a sliding window.
 */
string minWindow(string s, string t)
{
    unordered_map<char, int> tCount, window;
    for (char c : t)
        tCount[c]++;
    int required = tCount.size(), formed = 0;
    int left = 0, right = 0, minLen = INT_MAX, minLeft = 0;
    while (right < s.length())
    {
        window[s[right]]++; // Expand window
        if (tCount.find(s[right]) != tCount.end() && window[s[right]] == tCount[s[right]])
        {
            formed++;
        }
        while (formed == required && left <= right)
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                minLeft = left;
            }
            window[s[left]]--; // Shrink window
            if (tCount.find(s[left]) != tCount.end() && window[s[left]] < tCount[s[left]])
            {
                formed--;
            }
            left++;
        }
        right++;
    }
    return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl; // BANC
    return 0;
}