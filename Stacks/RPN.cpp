#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> st;

    for (string &s : tokens)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/")
        {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            if (s == "+")
                st.push(num1 + num2);
            else if (s == "-")
                st.push(num1 - num2);
            else if (s == "*")
                st.push(num1 * num2);
            else if (s == "/")
                st.push(num1 / num2);
        }
        else
            st.push(stoi(s)); // convert string to int.
    }
    return st.top();
}

int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << evalRPN(tokens) << endl; // 9
    return 0;
}