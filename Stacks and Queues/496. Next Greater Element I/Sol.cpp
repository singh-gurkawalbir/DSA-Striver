#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> umap;
        stack<int> st;

        for (int i = 0; i < nums1.size(); i++)
            umap[nums1[i]] = i;

        for (int i = 0; i < nums2.size(); i++)
        {
            int element = nums2[i];

            while (!st.empty() && element > st.top())
            {
                int idx = umap[st.top()];
                st.pop();
                ans[idx] = element;
            }
            if (umap.count(element))
            {
                st.push(element);
            }
        }
        return ans;
    }
};