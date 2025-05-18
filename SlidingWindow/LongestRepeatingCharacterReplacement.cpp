// LongestRepeatingCharacterReplacement.cpp
// Problem: Given a string s and an integer k, return the length of the longest substring containing the same letter after at most k replacements.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k)
{
    int n = s.size();
    vector<int> count(26, 0);
    int maxCount = 0, left = 0, result = 0;
    for (int right = 0; right < n; ++right)
    {
        count[s[right] - 'A']++;
        maxCount = max(maxCount, count[s[right] - 'A']);
        // If the window size minus the count of the most frequent char > k, shrink window
        while (right - left + 1 - maxCount > k)
        {
            count[s[left] - 'A']--;
            left++;
        }
        result = max(result, right - left + 1);
    }
    return result;
}

int main()
{
    vector<pair<string, int>> samples = {
        {"AABABBA", 1},
        {"ABAB", 2},
        {"AAAA", 2},
        {"ABCDE", 1},
        {"BAAAB", 2}};
    for (const auto &[s, k] : samples)
    {
        cout << "s: " << s << ", k: " << k << " -> ";
        cout << characterReplacement(s, k) << endl;
    }
    return 0;
}
