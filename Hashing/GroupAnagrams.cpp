#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
 * Problem: Group Anagrams
 * Given an array of strings, group the anagrams together.
 * An anagram is a word formed by rearranging the letters of another.
 * Example: "eat", "tea", "tan", "ate", "nat", "bat" -> [["eat","tea","ate"],["tan","nat"],["bat"]]
 */

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> map; // sorted string -> list of anagrams
    for (string s : strs)
    {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        map[sorted].push_back(s);
    }

    vector<vector<string>> result;
    for (auto &pair : map)
    {
        result.push_back(pair.second);
    }
    return result;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groups = groupAnagrams(strs);
    for (auto &group : groups)
    {
        for (string s : group)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
Time Complexity: O(N * K log K), where N is the number of strings and K is the maximum string length. Sorting each string dominates.
Space Complexity: O(N * K), for storing all strings in the hash map.
Explanation: Each string is sorted and stored in a hash map by its sorted form, grouping anagrams efficiently.
*/