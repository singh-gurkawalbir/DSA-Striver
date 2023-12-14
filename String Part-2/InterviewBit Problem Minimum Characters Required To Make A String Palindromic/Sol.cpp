#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solve(string str)
{
    int n = str.length();
    int left = 0;
    int right = n - 1;
    int added = 0;
    while (left < right)
    {
        // if left and right characters are same increase
        // left and decrease right pointer
        if (str[left] == str[right])
        {
            left++;
            right--;
        }
        // else think of adding some characters at front and
        // start comparing the elements again
        else
        {
            left = 0;
            added = n - right;
            while (str[left] == str[right])
            {
                added--;
                left++;
            }
            right--;
        }
    }
    return added;
}