#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    int getMax(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftSum = max(0, getMax(root->left, maxi));
        int rightSum = max(0, getMax(root->right, maxi));

        maxi = max((root->val + leftSum + rightSum), maxi);

        return (root->val + max(leftSum, rightSum));
    }

    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;

        getMax(root, maxi);
        return maxi;
    }
};