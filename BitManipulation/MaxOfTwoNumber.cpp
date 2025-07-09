#include <iostream>

using namespace std;

int getMax(int a, int b)
{
    int diff = a - b;
    int k = (diff >> 31) & 1; // get the Sign bit of the difference.

    return a - (k * diff);

    /*
     * if a >= b : k = 0; if a < b : k = 1;
     * if k = 0 => a - 0 = a.
     * if k = 1 => a - diff = b.
     */
}