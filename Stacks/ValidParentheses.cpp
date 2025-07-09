#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

bool isValid(const string &s)
{
    unordered_map<char, char> bracketPairs = {
        {')', '('},
        {'}', '{'},
        {']', '['}};
    stack<char> st;

    for (char c : s)
    {
        if (bracketPairs.count(c) == 0)
        {
            st.push(c);
        }
        else
        {
            if (st.empty() || st.top() != bracketPairs[c])
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string samples[] = {"()", "()[]{}", "(]", "([)]", "{[]}", "", "((()))", "([{}])", "((())"};
    for (const auto &s : samples)
    {
        cout << "Input: \"" << s << "\" -> " << (isValid(s) ? "Valid" : "Invalid") << endl;
    }
    return 0;
}

/*
Time Complexity: O(n), where n is the length of the string. Each character is pushed and popped at most once.
Space Complexity: O(n), for the stack in the worst case (all open brackets).
Explanation: We use a stack to match brackets, so each character is processed once and stack grows with input size.
*/