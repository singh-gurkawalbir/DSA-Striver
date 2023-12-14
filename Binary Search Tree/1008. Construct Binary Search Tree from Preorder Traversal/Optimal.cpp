#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    TreeNode *helper(vector<int> &arr, int l, int r)
    {
        // BASE CASE
        if (l > r)
            return NULL;

        // First element is root itself
        TreeNode *root = new TreeNode(arr[l]);

        int pos = l; // For corner case that only 1 element is given it the array
        for (int i = l + 1; i <= r; i++)
        { // Find the index of last element which is smaller than the root node
            if (arr[i] < root->val)
                pos = i;
            else
                break;
        }
        root->left = helper(arr, l + 1, pos);  // Make left subtree
        root->right = helper(arr, pos + 1, r); // Make right subtree
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int l = 0;                   // Left most element of array
        int r = preorder.size() - 1; // Right most element of the array
        return helper(preorder, l, r);
    }
};