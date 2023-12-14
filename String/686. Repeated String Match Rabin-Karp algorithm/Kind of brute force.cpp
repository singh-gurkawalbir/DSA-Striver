#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        // creating p as a copy of a,since we will append a letter on p ;-->
        string p = a;
        int i = 1;

        // this length(b) / length(a) + 2 is the max predicted times that can be found within the loop.  simple math ;-}
        // for example a= abcd, b= cdabcdabcdab , here loop will run 4 times because we have
        // to add ab in front and cd at back to make b a substring of a that is why we run hte loop an extra of 2 times
        // because of the front and back.
        while (i <= (b.length() / a.length()) + 2)
        {

            // checking if p is in the p if yes then return i;
            if (p.find(b) != -1)
                return i;

            // else append p with a
            else
                p += a;
            i++;
        }

        return -1;
    }
};