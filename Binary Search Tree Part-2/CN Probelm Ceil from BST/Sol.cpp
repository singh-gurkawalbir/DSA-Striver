#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

int findCeil(TreeNode *node, int x)
{
    TreeNode *p = node;
    int ans = -1;
    while (p)
    {
        if (p->val == x)
        {
            ans = p->val;
            return ans;
        }
        if (p->val > x)
        {
            ans = p->val;
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return ans;
}