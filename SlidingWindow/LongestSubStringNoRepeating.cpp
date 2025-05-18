#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
        return 0;

    unordered_set<char> seen;
    int maxLen = 0, left = 0;
    for (int right = 0; right < s.length(); right++)
    {
        while (seen.find(s[right]) != seen.end())
        {
            // shrink the window
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl; // 3
    return 0;
}