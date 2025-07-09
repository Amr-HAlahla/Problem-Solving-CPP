#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/* Problem: Given a string s and an integer k, return the length of the longest substring
 * containing at most k distinct characters.
 */

int lengthOfLongestSubstringKDistinct(const string &s, int k)
{
    if (k == 0 || s.empty())
        return 0;
    unordered_map<char, int> charCount;
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.length(); right++)
    {
        charCount[s[right]]++;
        while (charCount.size() > k)
        {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0)
                charCount.erase(s[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main()
{
    string s = "eceba";
    int k = 2;
    cout << lengthOfLongestSubstringKDistinct(s, k) << endl; // 3 ("ece")
    s = "aa";
    k = 1;
    cout << lengthOfLongestSubstringKDistinct(s, k) << endl; // 2 ("aa")
    s = "abcadcacacaca";
    k = 3;
    cout << lengthOfLongestSubstringKDistinct(s, k) << endl; // 11 ("cadcacacaca")
    return 0;
}
