#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    vector<int> bottomView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mpp;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode *TreeNode = it.first;
            int line = it.second;
            if (mpp.find(line) == mpp.end())
                mpp[line] = TreeNode->val;

            if (TreeNode->left != NULL)
            {
                q.push({TreeNode->left, line - 1});
            }
            if (TreeNode->right != NULL)
            {
                q.push({TreeNode->right, line + 1});
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};