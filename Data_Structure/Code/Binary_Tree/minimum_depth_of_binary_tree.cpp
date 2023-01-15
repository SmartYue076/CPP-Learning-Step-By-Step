#include <iostream>
#include <queue>
#include <algorithm>
#include "basic_binary_tree.h"
using namespace std;

// recursion
int getDepth(TreeNode *node)
{
    if (node == NULL)
        return 0;
    int leftDepth = getDepth(node->left);  
    int rightDepth = getDepth(node->right); 
                                            
    if (node->left == NULL && node->right != NULL)
        return 1 + rightDepth;
    else if (node->left != NULL && node->right == NULL)
        return 1 + leftDepth;
    int result = 1 + min(leftDepth, rightDepth);
    return result;
}

int minDepth(TreeNode *root)
{
    return getDepth(root);
}

// // iteration
// int minDepth(TreeNode *root)
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
//             if ((node->left == nullptr) && (node->right == nullptr))
//                 return depth;
//         }
//     }
//     return depth;
// }

int main()
{
    TreeNode *node4 = new TreeNode(5, nullptr, nullptr);
    TreeNode *node3 = new TreeNode(4, nullptr, nullptr);
    TreeNode *node1 = new TreeNode(2, node3, node4);
    TreeNode *node2 = new TreeNode(3, nullptr, nullptr);
    TreeNode *root = new TreeNode(1, node1, node2);
    cout << minDepth(root) << endl;
    return 0;
}