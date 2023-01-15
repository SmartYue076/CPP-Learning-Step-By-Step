#include <iostream>
#include <queue>
#include <algorithm>
#include "basic_binary_tree.h"
using namespace std;

// recursion
int getDepth(TreeNode *node)
{
    if (node == nullptr)
        return 0;
    int leftdepth = getDepth(node->left);
    int rightdepth = getDepth(node->right);
    int depth = 1 + max(leftdepth, rightdepth); // 1 for current node
    return depth;
}

int maxDepth(TreeNode *root)
{
    return getDepth(root);
}

// // iteration
// int maxDepth(TreeNode *root)
// {
//     int depth = 0;
//     if (root == nullptr)
//         return depth;
//     queue<TreeNode *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         int size = q.size();
//         depth++;
//         for (int i = 0; i < size; i++)
//         {
//             TreeNode *node = q.front();
//             q.pop();
//             if (node->left != nullptr)
//                 q.push(node->left);
//             if (node->right != nullptr)
//                 q.push(node->right);
//         }
//     }
//     return depth;
// }

int main()
{
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(3, node6, nullptr);
    TreeNode *node3 = new TreeNode(3, nullptr, node5);
    TreeNode *node1 = new TreeNode(2, node3, nullptr);
    TreeNode *node2 = new TreeNode(2, nullptr, node4);
    TreeNode *root = new TreeNode(1, node1, node2);
    cout << maxDepth(root) << endl;
    return 0;
}