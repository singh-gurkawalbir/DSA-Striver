#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "Tree.h"
using namespace std;

class Solution
{
    TreeNode *prev = NULL;

public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();

            if (cur->right != NULL)
            {
                st.push(cur->right);
            }
            if (cur->left != NULL)
            {
                st.push(cur->left);
            }
            if (!st.empty())
            {
                cur->right = st.top();
            }
            cur->left = NULL;
        }
    }
};
