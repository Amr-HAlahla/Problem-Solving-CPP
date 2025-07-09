#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Brief Description of the Problem:
Given an array of stock prices where prices[i] is the price of a given stock on the ith day,
find the maximum profit you can achieve by buying on one day and selling on another later day.
*/

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices)
    {
        if (price < minPrice)
            minPrice = price;
        else
            maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // 5
    cout << "Max Profit: " << maxProfit(prices) << endl;
    return 0;
}

/*
Time Complexity: O(n), where n is the number of days (prices). We scan the array once.
Space Complexity: O(1), as we use only a few variables for tracking min price and max profit.
Explanation: We keep track of the minimum price so far and update the max profit in a single pass.
*/
