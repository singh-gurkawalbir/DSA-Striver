#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Tree.h"
using namespace std;

class Solution
{
public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(TreeNode *node)
    {
        queue<TreeNode *> q;
        int size;
        q.push(node);
        while (!q.empty())
        {
            size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                if (curr->left != NULL || curr->right != NULL)
                {
                    swap(curr->left, curr->right);
                }
            }
        }
    }

    //! OR
    //? void mirror(Node *node)
    //? {
    //?     queue<Node *> q;
    //?     int size;
    //?     q.push(node);
    //?     while (!q.empty())
    //?     {
    //?         size = q.size();
    //?         for (int i = 0; i < size; i++)
    //?         {
    //?             Node *curr = q.front();
    //?             q.pop();
    //?             if (curr->left)
    //?                 q.push(curr->left);
    //?             if (curr->right)
    //?                 q.push(curr->right);
    //?             if (curr->left != NULL or curr->right != NULL)
    //?             {
    //?                 swap(curr->left, curr->right);
    //?             }
    //?         }
    //?     }
    //? }
};