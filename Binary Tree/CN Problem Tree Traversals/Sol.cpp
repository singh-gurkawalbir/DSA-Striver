#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include "Tree.h"
using namespace std;

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<vector<int>> v;
    if (root == NULL)
        return v;
    stack<pair<TreeNode *, int>> s;
    vector<int> pre, post, in;
    s.push({root, 1}); // Push Root Element with Count = 1

    while (!s.empty())
    {
        auto it = s.top();

        if (it.second == 1) // PREORDER
        {
            pre.push_back(it.first->val);
            s.top().second = 2;
            if (it.first->left != NULL)
                s.push({it.first->left, 1});
        }

        else if (it.second == 2) // INORDER
        {
            in.push_back(it.first->val);
            s.top().second = 3;
            if (it.first->right != NULL)
                s.push({it.first->right, 1});
        }

        else if (it.second == 3) // POSTORDER
        {
            post.push_back(it.first->val);
            s.pop();
        }
    }
    v.push_back(in);
    v.push_back(pre);
    v.push_back(post);
    return v;
}