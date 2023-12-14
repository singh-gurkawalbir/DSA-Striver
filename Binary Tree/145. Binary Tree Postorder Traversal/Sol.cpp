#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;

void postorder(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
        return;
    else
    {
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> result;
    postorder(root, result);
    return result;
}