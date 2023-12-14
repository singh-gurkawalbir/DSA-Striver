#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    void inord(TreeNode *root, int &K, int &ans)
    {
        if (root == NULL)
            return;
        inord(root->right, K, ans);
        K--;
        if (K == 0)
        {
            ans = root->val;
        }
        inord(root->left, K, ans);
    }
    int kthLargest(TreeNode *root, int K)
    {
        int ans = -1;
        inord(root, K, ans);
        return ans;
    }
};
