#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    void inord(TreeNode *root, int &k, int &ans)
    {
        if (root == NULL)
            return;
        inord(root->left, k, ans);
        k--;
        if (k == 0)
        {
            ans = root->val;
        }
        inord(root->right, k, ans);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int ans = -1;
        inord(root, k, ans);
        return ans;
    }
};
