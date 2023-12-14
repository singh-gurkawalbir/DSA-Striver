#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "Tree.h"
using namespace std;

class BSTIterator
{
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root)
    {
        pushall(root);
        // this will push all the elements
        // till the extreme left onto the stack.
    }

    void pushall(TreeNode *root)
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
    }
    // return the next smallest number
    int next()
    {
        TreeNode *top = s.top();
        s.pop();
        pushall(top->right);
        return top->val;
    }
    // return whether we have a next smallest number
    bool hasNext()
    {
        return !s.empty();
    }
};