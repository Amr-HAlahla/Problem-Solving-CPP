#include <iostream>
#include <vector>

using namespace std;

/* Problem:
 * Given two integers left and right, return the bitwise AND of all numbers in the range [left, right] (inclusive).
 * Example:
 * Input: left = 5, right = 7
 * Output: 4
 * 5 = 101, 6 = 110, 7 = 111
 * 101 & 110 & 111 = 100 = 4
 */

/* Key Idea:
 * Whenever numbers in a range differ in a bit, the result of that bit in AND becomes 0.
 * So you need to find the common prefix of left and right.
 * WHY ?
 * In ANDing everything from left to right, the changing bits will eventually be zeroed out.
 * So we only want the bits that don't change — the common leading bits of left and right.
 *
 * how do we find those common leading bits?
 * We shift both left and right rightwards until they become equal.
 * That means:
 *      - We’re removing differing bits one by one.
 *      - When they match, we’ve found the common prefix.
 * Then we shift left back by the number of shifts to rebuild the number.
 */

int rangeBitwiseAnd(int left, int right)
{
    int shift = 0;

    // Keep shifting until both numbers are equal
    while (left < right)
    {
        left >>= 1;
        right >>= 1;
        shift++;
    }

    // Shift back the result to the left
    return left << shift;
}

/* Time Complixty:
 * O(1) for 32-bit integers (at most 32 shifts)
 */