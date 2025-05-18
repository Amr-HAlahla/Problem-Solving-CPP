#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st; // store indices

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[i] > nums[st.top()])
        {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

int main()
{
    vector<int> nums = {4, 5, 2, 25};
    vector<int> result = nextGreaterElement(nums);
    for (int x : result)
    {
        cout << x << " "; // 5 25 25 -1
    }
    return 0;
}