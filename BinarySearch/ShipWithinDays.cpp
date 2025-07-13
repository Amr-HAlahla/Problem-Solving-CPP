#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canShip(vector<int> &weights, int capacity, int D)
{
    int days = 1, current = 0;

    for (int w : weights)
    {
        if (current + w > capacity)
        {
            days++;
            current = 0;
        }
        current += w;
    }
    return days <= D;
}

int shipWithinDays(vector<int> &weights, int D)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (canShip(weights, mid, D))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}