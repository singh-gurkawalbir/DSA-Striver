#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        TreeNode *cur = root;
        vector<int> preorder;
        while (cur != NULL)
        {
            if (cur->left == NULL) // no left node then directly push in preorder and go right
            {
                preorder.push_back(cur->val);
                cur = cur->right;
            }
            else // there is a left node
            {
                // find preorder predecessor
                TreeNode *predecessor = cur->left; // predecessor will be
                // the rightmost of left until it reaches null or back
                // to the current node (as we might have already created thread from it.
                while (predecessor->right != cur && predecessor->right != NULL)
                    predecessor = predecessor->right;
                if (predecessor->right == NULL) // thread creation as visiting first time
                {
                    predecessor->right = cur;
                    preorder.push_back(cur->val);
                    cur = cur->left;
                }
                else // thread deletion to avoid cycle and pushing node in preorder
                {
                    predecessor->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return preorder;
    }
};