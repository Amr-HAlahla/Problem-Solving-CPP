#include <iostream>
using namespace std;

int add(int a, int b)
{
    while (b != 0)
    {
        unsigned carry = a & b; // Common bits = carry
        a = a ^ b;              // Sum without carry
        b = carry << 1;         // Shift carry left
    }
    return a;
}