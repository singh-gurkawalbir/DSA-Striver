#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        queue<pair<TreeNode *, long long int>> q;
        int ans = 0;
        q.push({root, 0});

        while (!q.empty())
        {
            int left, right;
            int n = q.size();
            int mini = q.front().second;
            for (int i = 0; i < n; i++)
            {
                long long int curr = q.front().second - mini;
                TreeNode *temp = q.front().first;
                q.pop();
                if (i == 0)
                    left = curr;
                if (i == n - 1)
                    right = curr;
                if (temp->left)
                    q.push({temp->left, curr * 2 + 1});
                if (temp->right)
                    q.push({temp->right, curr * 2 + 2});
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};