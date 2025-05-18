#include <vector>
#include <iostream>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

int main() {
    vector<int> nums = {2, 2, 1};
    cout << "Single number is: " << singleNumber(nums) << endl;
    return 0;
}