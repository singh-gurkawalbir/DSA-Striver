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
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left)
            {
                TreeNode *pre = cur->left;
                while (pre->right)
                {
                    pre = pre->right;
                }
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};