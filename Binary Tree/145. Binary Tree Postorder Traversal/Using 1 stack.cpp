#include <iostream>
#include <vector>
#include <stack>
#include "Tree.h"
using namespace std;

vector<int> postOrderTrav(TreeNode *root)
{
    vector<int> postOrder;
    if (root == NULL)
        return postOrder;

    stack<TreeNode *> st;
    while (root != NULL || !st.empty())
    {

        if (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->val);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);
                }
            }
            else
                root = temp;
        }
    }
    return postOrder;
}