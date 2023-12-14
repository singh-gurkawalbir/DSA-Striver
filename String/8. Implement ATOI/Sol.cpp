#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        // cin.tie(NULL); it help to run code fast
        int i = 0, n = str.length();
        if (n == 0)
        {
            return 0;
        }
        while (str[i] == ' ') // removing all the white space from given string
            i++;
        int flag = 0;        // To check weather the integer is positive or negitive
        long long int a = 0; // To over come the overflow problem if you use int it may overflow
        if (str[i] == '-')
        {
            flag = 1;
            i++;
        }
        if (str[i] == '+' && flag == 0) // To overcome test case like '+42'
            i++;

        while (i < n && str[i] >= '0' && str[i] <= '9')
        {
            a = a * 10 + (str[i] - '0');  // convertion from char to interger
            if (a > INT_MAX && flag == 0) // check whether a is greater then INTMAX(2^31-1);
                return INT_MAX;
            if (-a < INT_MIN && flag == 1) // check for INTMIN(-2^31);
                return INT_MIN;
            i++;
        }

        if (flag == 1)
            return -a;
        return a;
    }
};