#include <iostream>
#include "basic_binary_tree.h"
using namespace std;

// recursion
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return nullptr;

    if (root->val == val)
        return root;
    else if ((root->val) > val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

// // iteration
// TreeNode *searchBST(TreeNode *root, int val)
// {
//     while (root != nullptr)
//     {
//         if (root->val == val)
//             return root;
//         else if ((root->val) > val)
//             root = root->left;
//         else
//             root = root->right;
//     }
//     return nullptr;
// }

int main()
{
    TreeNode *node2 = new TreeNode(7);
    TreeNode *node4 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node1 = new TreeNode(4, node3, node4);
    TreeNode *root = new TreeNode(6, node1, node2);
    cout << searchBST(root, 4)->val << endl;
    return 0;
}