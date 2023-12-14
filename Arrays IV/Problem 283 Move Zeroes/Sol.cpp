#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[count]);
                count++;
            }
        }
    }
    // void moveZeroes(vector<int> &nums)
    // {
    //     stable_partition(begin(nums), end(nums), [](int i)
    //                      { return i; });
    // }
};
