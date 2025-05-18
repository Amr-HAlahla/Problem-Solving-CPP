#include <iostream>
#include <vector>
using namespace std;

// vector passed by reference for in-place modifications
void reverseArray(vector<int> &arr)
{
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    reverseArray(arr);
    for (int x : arr)
    {
        cout << x << " "; // 4 3 2 1
    }
    return 0;
}