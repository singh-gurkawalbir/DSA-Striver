#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

void findPreSuc(TreeNode *root, TreeNode *&pre, TreeNode *&suc, int val)
{
    suc = NULL;
    pre = NULL;
    TreeNode *s = root;
    while (s)
    {
        if (s->val > val)
        {
            suc = s;
            s = s->left;
        }
        else
        {
            s = s->right;
        }
    }
    TreeNode *p = root;
    while (p)
    {
        if (p->val < val)
        {
            pre = p;
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
}