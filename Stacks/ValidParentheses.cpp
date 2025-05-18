#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

bool isValid(const string& s)
{
    unordered_map<char, char> bracketPairs = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
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
    for (const auto& s : samples)
    {
        cout << "Input: \"" << s << "\" -> " << (isValid(s) ? "Valid" : "Invalid") << endl;
    }
    return 0;
}