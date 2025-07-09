#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Problem Brief:
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 * A permutation of a string is an arrangement of its characters in any order.
 * The order of characters does not matter.
 */

bool checkInclusion(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    if (n > m)
        return false;

    vector<int> count1(26, 0), count2(26, 0);

    // Count frequency of each character in s1 and first window of s2
    for (int i = 0; i < n; ++i)
    {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    // Slide the window over s2
    for (int i = n; i < m; i++)
    {
        if (count1 == count2)
            return true;

        count2[s2[i - n] - 'a']--;
        count2[s2[i] - 'a']++;
    }
    // Check the last window
    return count1 == count2;
}

int main()
{
    // Sample test cases
    vector<pair<string, string>> samples = {
        {"ab", "eidbaooo"},
        {"ab", "eidboaoo"},
        {"adc", "dcda"},
        {"hello", "ooolleoooleh"}
    };

    for (const auto& [s1, s2] : samples)
    {
        cout << "s1: " << s1 << ", s2: " << s2 << " -> ";
        if (checkInclusion(s1, s2))
        {
            cout << "True\n";
        }
        else
        {
            cout << "False\n";
        }
    }
    return 0;
}
