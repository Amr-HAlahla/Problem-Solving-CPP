#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &, int, int);

// Rotate array by K.
void rotateArray(vector<int> &arr, int k)
{
    if (arr.size() == 0)
    {
        return;
    }
    // Normalize k
    int n = arr.size();
    k = k % n;

    reverseArray(arr, 0, n - 1);

    reverseArray(arr, 0, k - 1);

    reverseArray(arr, k, n - 1);
}

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
    rotateArray(arr, 3);
    for (int x : arr)
    {
        cout << x << " "; // 4 3 2 1
    }
    return 0;
}