#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int C = 0, pos = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                pos = i;
                C++;
                for (int j = 1; j < needle.size(); j++)
                {
                    if (haystack[i + j] == needle[j])
                        C++;
                    else
                    {
                        C = 0;
                        pos = -1;
                        break;
                    }
                }
            }
            if (C == needle.size())
                break;
        }
        return pos;
    }
};