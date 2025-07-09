#include <iostream>
using namespace std;

int absValue(int x)
{
    int mask = x >> 31; // get the Sign Bit.
    return (x ^ mask) - mask;

    /*
     * if x >= 0 : mask = 0s, if x < 0 : mask = 1s.
     * if mask = 0 => (x ^ 0) - 0 = x - 0 = x.
     * if mask = -1 (all 1s) => (x ^ -1) - (-1) = (~x) + 1 = -x
     */
}