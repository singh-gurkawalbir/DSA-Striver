#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    //* bool checkTree(TreeNode *root)
    //* {
    //*    return (root->val == root->left->val + root->right->val);
    //* }

    //? OR

    bool checkTree(TreeNode *root)
    {
        if (root->right && root->left)
            return (root->val == root->left->val + root->right->val);

        else if (root->left)
            return (root->val == root->left->val);

        else
            return (root->val == root->right->val);
    }
};