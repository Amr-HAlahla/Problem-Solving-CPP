#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    reverseArray(arr, 1, 3);
    for (int x : arr)
    {
        cout << x << " "; // 1, 4, 3, 2, 5
    }
    return 0;
}