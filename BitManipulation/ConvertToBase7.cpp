#include <string>
#include <algorithm>
using namespace std;

string convertToBase7(int num)
{
    if (num == 0)
        return "0";

    bool isNegative = num < 0;
    num = abs(num);

    string result;
    while (num > 0)
    {
        int remainder = num % 7;
        result += to_string(remainder); // build in reverse
        num /= 7;
    }

    reverse(result.begin(), result.end());
    return isNegative ? "-" + result : result;
}