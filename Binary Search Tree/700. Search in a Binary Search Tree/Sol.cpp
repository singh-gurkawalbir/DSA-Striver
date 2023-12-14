#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

//? Iterative
TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != nullptr && root->val != val)
    {
        root = (root->val > val) ? root->left : root->right;
    }
    return root;
}

// ? Recursive
TreeNode *searchBST(TreeNode *root, int val)
{
    if (!root)
        return nullptr;
    if (root->val == val)
        return root;
    else if (root->val > val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}