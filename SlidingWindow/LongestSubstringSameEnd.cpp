#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

pair<vector<string>, int> longestSubstringsSameEnds(const string &s)
{
    unordered_map<char, int> firstIndex; // char : first index
    int maxLen = 0;
    vector<string> results;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (firstIndex.find(c) == firstIndex.end())
        {
            firstIndex[c] = i;
        }
        else
        {
            int startIndex = firstIndex[c];
            int len = i - startIndex + 1;
            string substr = s.substr(startIndex, len);

            if (len > maxLen)
            {
                maxLen = len;
                results = {substr}; // new max found, reset
            }
            else if (len == maxLen)
            {
                results.push_back(substr); // same max, add it
            }
        }
    }

    return {results, maxLen};
}

int main()
{
    string input = "abcabcab";
    // string input = "halahla";
    auto [substrings, length] = longestSubstringsSameEnds(input);

    cout << "Longest substrings that start and end with the same character:\n";
    for (const auto &str : substrings)
    {
        cout << "Substring: \"" << str << "\"\n";
    }
    cout << "Length: " << length << endl;

    return 0;
}
