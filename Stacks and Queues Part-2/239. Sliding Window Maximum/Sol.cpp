#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k)
            // check is the element is out of bounds.If it is pop it out.
            {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i])
            // The thing is that we have to maintain a decreasing
            // order so if the new is largest we pop the smaller
            // elements earlier present in the dq
            {
                dq.pop_back();
            }

            dq.push_back(i);
            if (i >= k - 1)
            {
                // for every window insert the answer
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};