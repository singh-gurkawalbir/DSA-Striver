#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string s = "1";
        for (int i = 2; i <= n; i++)
        { // Find n'th term by generating all terms from 2 to n-1xxxx.
            string t = "";

            int cnt = 1;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != s[i + 1])
                {
                    t += to_string(cnt); // convert integer to string use to_string fn
                    t += s[i];
                    cnt = 1; // Reset count
                }
                else
                    cnt++; // if match increment count
            }
            s = t; // Update String s
        }
        return s;
    }
};