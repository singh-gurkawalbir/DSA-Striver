#include <iostream>
#include <vector>
#include <stack>
#include "Tree.h"
using namespace std;

class Solution
{
    // Inorder - Left Subtree -> Root -> Right Subtree
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> ans;

        // 1. Make root as the starting node, that is currNode
        TreeNode *currNode = root;
        while (currNode || !st.empty())
        {
            // 2. Now add all the left subtree nodes to the stack
            while (currNode)
            {
                st.push(currNode);
                currNode = currNode->left;
            }
            // 3. Pick out the top node, put it in answer array
            currNode = st.top();
            st.pop();

            ans.push_back(currNode->val);
            // 4. Update currNode as below, this will take care of the right subtree
            currNode = currNode->right;
        }
        return ans;
    }
};