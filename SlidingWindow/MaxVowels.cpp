#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Returns the maximum number of vowels in any substring of length k in s.
int maxVowels(string s, int k)
{
    if (k > s.length())
        return 0;
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int maxCount = 0, windowCount = 0;
    // First window
    for (int i = 0; i < k; i++)
    {
        if (vowels.find(s[i]) != vowels.end())
            windowCount++;
    }
    maxCount = windowCount;

    // Slide window
    for (int i = k; i < s.length(); i++)
    {
        if (vowels.find(s[i - k]) != vowels.end())
            windowCount--;

        if (vowels.find(s[i]) != vowels.end())
            windowCount++;

        maxCount = max(maxCount, windowCount);
    }

    return maxCount;
}

int main()
{
    string s1 = "abciiidef";
    int k1 = 3;
    cout << maxVowels(s1, k1) << endl; // 3

    string s2 = "aeiou";
    int k2 = 2;
    cout << maxVowels(s2, k2) << endl; // 2

    string s3 = "leetcode";
    int k3 = 3;
    cout << maxVowels(s3, k3) << endl; // 2

    return 0;
}