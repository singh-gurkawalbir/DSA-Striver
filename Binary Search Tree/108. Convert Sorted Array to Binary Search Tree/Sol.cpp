#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int start, int end)
    {

        // base case
        // If the left pointer crosses right return null;
        if (start > end)
        {
            return NULL;
        }

        // as middle of the array will be the root node
        int mid = (start + end) / 2;
        TreeNode *temp = new TreeNode(nums[mid]);

        // left part from middle will be left subtree
        temp->left = helper(nums, start, mid - 1);

        // right part of array will be right subtree
        temp->right = helper(nums, mid + 1, end);
        return temp;
    }
};