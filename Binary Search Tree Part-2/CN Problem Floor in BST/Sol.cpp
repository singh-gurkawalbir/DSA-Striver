#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

int floorInBST(TreeNode *root, int X)
{
    TreeNode *p = root;
    int ans = -1;
    while (p)
    {
        if (p->val == X)
        {
            ans = p->val;
            return ans;
        }
        if (p->val < X)
        {
            ans = p->val;
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    return ans;
}
