#include <iostream>
using namespace std;

int countSetBits(int n){
    int count = 0;
    while(n){
        n = n & (n - 1);
        count++;
    }
    return count;

    // Each iteration removes the lowest set bit from n, so count gives total set bits.
}