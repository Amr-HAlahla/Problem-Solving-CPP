#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int hoursNeeded(vector<int> &piles, int k)
{
    int hours = 0;
    for (int bananas : piles)
    {
        hours += (bananas + k - 1) / k; // same as ceil(bananas / k)
    }
    return hours;
}

int minEatingBananas(vector<int>& piles, int h){
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    while(low < high){
        int mid = (low + high) / 2;
        if(hoursNeeded(piles, mid) <= h)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}