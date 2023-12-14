#include <iostream>
#include <vector>
#include <stack>
#include "Tree.h"
using namespace std;

void preorderTraversalHelper(TreeNode *root, vector<int> &res)
{
    if (root)
    {
        res.push_back(root->val);

        if (root->left)
            preorderTraversalHelper(root->left, res);

        if (root->right)
            preorderTraversalHelper(root->right, res);
    }

    return;
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    preorderTraversalHelper(root, res);
    return res;
}