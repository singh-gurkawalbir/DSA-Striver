#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MAX, LONG_MIN);
    }

    bool helper(TreeNode *root, long maxVal, long minVal)
    {
        if (root == NULL)
            return true;
        if (root->val >= maxVal || root->val <= minVal)
            return false;

        return (helper(root->left, root->val, minVal) && helper(root->right, maxVal, root->val));
    }
};

//*     void helper(TreeNode *root, vector<int> &ans)
//*     {
//*         if (root == NULL)
//*             return;
//*         helper(root->left, ans);
//*         ans.push_back(root->val);
//*         helper(root->right, ans);
//*     }
//*     bool isValidBST(TreeNode *root)
//*     {
//*         vector<int> ans;
//*         helper(root, ans);
//*         for (int i = 0; i < ans.size() - 1; i++)
//*         {
//*             if (ans[i] >= ans[i + 1])
//*                 return false;
//*         }
//*         return true;
//*     }