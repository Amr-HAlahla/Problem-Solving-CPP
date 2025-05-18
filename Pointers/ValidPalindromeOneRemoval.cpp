#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Helper function to check palindrome in substring [left, right]
bool isPalinRange(const string &s, int left, int right)
{
    while (left < right)
    {
        if (tolower(s[left]) != tolower(s[right]))
            return false;
        left++;
        right--;
    }
    return true;
}

// Returns true if s is a palindrome or can become one by removing at most one character
bool validPalindrome(string s)
{
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        while (left < right && !isalnum(s[left]))
            left++;
        while (right > left && !isalnum(s[right]))
            right--;
        if (tolower(s[left]) != tolower(s[right]))
        {
            // Try skipping either left or right character
            return isPalinRange(s, left + 1, right) || isPalinRange(s, left, right - 1);
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    string s1 = "abca";
    string s2 = "raceacar";
    string s3 = "A man, a plan, a canal: Panama";
    cout << (validPalindrome(s1) ? "True" : "False") << endl; // True
    cout << (validPalindrome(s2) ? "True" : "False") << endl; // True
    cout << (validPalindrome(s3) ? "True" : "False") << endl; // True
    return 0;
}
