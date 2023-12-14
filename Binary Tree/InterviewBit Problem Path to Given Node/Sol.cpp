#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

bool getPath(TreeNode *root, vector<int> &ans, int B)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(root->val);

    if (root->val == B)
    {
        return true;
    }

    if (getPath(root->left, ans, B) || getPath(root->right, ans, B))
    {
        return true;
    }

    ans.pop_back();
    return false;
}

vector<int> solve(TreeNode *A, int B)
{
    vector<int> ans;
    if (A == NULL)
        return ans;

    getPath(A, ans, B);
    return ans;
}