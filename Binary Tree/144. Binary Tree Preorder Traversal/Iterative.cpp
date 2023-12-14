#include <iostream>
#include <vector>
#include <stack>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        stack<TreeNode *> stack;
        if (root == NULL)
            return preorder;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *curr = stack.top();
            stack.pop();
            preorder.push_back(curr->val);
            if (curr->right != NULL)
                stack.push(curr->right);
            if (curr->left != NULL)
                stack.push(curr->left);
        }
        return preorder;
    }
};