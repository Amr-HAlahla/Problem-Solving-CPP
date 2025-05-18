#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(vector<string>& result, string current, int open, int close, int n) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }
    if (open < n) {
        backtrack(result, current + "(", open + 1, close, n);
    }
    if (close < open) {
        backtrack(result, current + ")", open, close + 1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack(result, "", 0, 0, n);
    return result;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<string> parentheses = generateParenthesis(n);
    for (const string& s : parentheses) {
        cout << s << endl;
    }
    return 0;
}