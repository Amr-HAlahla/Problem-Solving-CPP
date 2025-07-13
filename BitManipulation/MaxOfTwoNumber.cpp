#include <iostream>

using namespace std;

int getMax(int a, int b)
{
    int diff = a - b;
    int k = (diff >> 31) & 1; // ANDing with 1 for Isolation, to extract the sign bit.

    return a - (k * diff);

    /*
     * if a >= b : k = 0; if a < b : k = 1;
     * if k = 0 => a - 0 = a.
     * if k = 1 => a - diff = b.
     */
}