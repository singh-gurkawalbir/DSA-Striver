#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    bool l2r = true;

    while (!q.empty())
    {
        int size = q.size();
        // define the size of the vector
        // otherwise you will get an error
        // runtime error: reference binding to null pointer
        // of type 'int' (stl_vector.h)
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            // find position to fill node's value
            int index = l2r ? i : size - 1 - i;
            level[index] = temp->val;

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        // after this level
        l2r = !l2r;
        ans.push_back(level);
    }
    return ans;
}
