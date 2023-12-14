#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // Initializing table with -0
    int end = 1; // also represents the length of the palindromic string found
    int strt = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++) // checking for substring of length 2.
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            strt = i; // Updating the start
            end = 2;  // Updating max len
        }
    }
    for (int j = 2; j < n; j++)
    { // Checking for length greater than 2
        for (int i = 0; i < n - j; i++)
        {
            int lft = i;
            int rght = i + j;

            if (dp[lft + 1][rght - 1] == 1 && s[lft] == s[rght])
            {
                dp[lft][rght] = 1;
                strt = i;    // Updating the start
                end = j + 1; // Updating max len
            }
        }
    }
    return s.substr(strt, end);
}