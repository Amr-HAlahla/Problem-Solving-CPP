#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

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