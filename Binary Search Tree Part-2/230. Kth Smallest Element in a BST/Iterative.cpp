#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        TreeNode *curr = root;
        int flag = 0;
        stack<TreeNode *> st;
        while (flag == 0)
        {
            if (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            else if (!st.empty())
            {
                curr = st.top();
                st.pop();
                k--;
                if (k == 0)
                {
                    return curr->val;
                }
                curr = curr->right;
            }
            else
                flag = 1;
        }
        return -1; /* will never return -1 as solution always exists */
    }
};