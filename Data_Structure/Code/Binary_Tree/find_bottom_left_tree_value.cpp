#include <iostream>
#include <queue>
#include <algorithm>
#include "basic_binary_tree.h"
using namespace std;

// iteration
int findBottomLeftValue(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    if ((root->left == nullptr) && (root->right == nullptr))
        return root->val;

    int result = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (i == 0)
                result = node->val;
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
    }
    return result;
}

// // recursion
// int result = 0;
// int max_depth = INT32_MIN;

// void findValue(TreeNode *node, int depth)
// {
//     if (node->left == nullptr && node->right == nullptr)
//     {
//         if (depth > max_depth)
//         {
//             max_depth = depth;
//             result = node->val;
//         }
//         return;
//     }

//     if (node->left)
//     {
//         depth++;
//         findValue(node->left, depth);
//         depth--;
//     }

//     if (node->right)
//     {
//         depth++;
//         findValue(node->right, depth);
//         depth--;
//     }
//     return;
// }

// int findBottomLeftValue(TreeNode *root)
// {
//     if (root == nullptr)
//         return 0;
//     findValue(root, 0);
//     return result;
// }

int main()
{
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);
    TreeNode *node2 = new TreeNode(20, nullptr, node4);
    TreeNode *node1 = new TreeNode(30);
    TreeNode *root = new TreeNode(1, node1, node2);
    cout << findBottomLeftValue(root) << endl;
    return 0;
}