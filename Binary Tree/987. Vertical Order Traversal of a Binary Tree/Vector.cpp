#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> out;
        map<int, vector<int>> mp;
        queue<pair<TreeNode *, int>> q;
        // distance zero for root.
        q.push({root, 0});

        while (!q.empty())
        {
            int n = q.size();
            // Temporary level map to store data at this level.
            map<int, vector<int>> level;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front().first;
                int d = q.front().second;
                q.pop();
                level[d].push_back(node->val);
                // distance -1 for left move.
                if (node->left)
                    q.push({node->left, d - 1});
                // distanace +1 for right move
                if (node->right)
                    q.push({node->right, d + 1});
            }
            for (auto el : level)
            {
                // sort values at same level
                sort(el.second.begin(), el.second.end());
                // append vector to existing vector.
                mp[el.first].insert(mp[el.first].end(), el.second.begin(), el.second.end());
            }
        }
        for (auto el : mp)
        {
            out.push_back(el.second);
        }
        return out;
    }
};