#include <cstdint>

uint32_t reverseBits(uint32_t n)
{
    uint32_t reversed = 0;

    for (int i = 0; i < 32; i++)
    {
        reversed <<= 1;      // shift left to make room for next bit
        reversed |= (n & 1); // get last bit of n and add it
        n >>= 1;             // shift n right to process next bit
    }
}

/* Key Idea: You need to go through all 32 bits of the input number:
 *
 * 1- Extract the last bit from the input using (n & 1)
 *  - n & 1 = n & 00000001 = First bit from n.
 * 2- Add it to the reversed number by shifting current result left and OR-ing it
 * 3- Shift n right by 1 to go to the next bit
 * 4- Repeat for all 32 bits
 *
 * Time : O(32) → constant time since it's always 32 bits.
 * Space : O(1).
 */
