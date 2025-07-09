#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

/*
Brief Description of the Problem:
Given a string s, find the length of the longest substring without repeating characters.
*/

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> seen;
    int maxLen = 0, left = 0;

    for (int right = 0; right < s.length(); right++)
    {
        while (seen.find(s[right]) != seen.end())
        {
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
/*
Time Complexity: O(n), where n is the length of the string. Each character is visited at most twice (once by right, once by left pointer).
Space Complexity: O(min(n, m)), where m is the size of the character set. We store at most one of each character in the set.
Explanation: The sliding window expands and contracts, but each character is only added and removed from the set once, so the work is linear.
*/