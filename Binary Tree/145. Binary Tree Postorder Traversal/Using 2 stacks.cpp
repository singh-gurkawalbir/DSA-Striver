#include <iostream>
#include <vector>
#include <stack>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(root);
        while (!s1.empty())
        {
            root = s1.top();
            s2.push(root);
            s1.pop();
            if (root->left)
                s1.push(root->left);
            if (root->right)
                s1.push(root->right);
        }
        while (!s2.empty())
        {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};