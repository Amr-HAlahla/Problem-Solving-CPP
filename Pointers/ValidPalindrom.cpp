#include <iostream>
#include <string>
#include <cctype> // for tolower, isalnum.
using namespace std;

bool isPalindrome(string s)
{
    int left = 0, right = s.length();
    while (left < right)
    {
        while (left < right && !isalnum(s[left]))
            left++;
        while (right > left && !isalnum(s[right]))
            right--;

        if (tolower(s[left]) != tolower(s[right]))
            return false;

        left++;
        right--;
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << (isPalindrome(s) ? "True" : "False") << endl; // True
    return 0;
}