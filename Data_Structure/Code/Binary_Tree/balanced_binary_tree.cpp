#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include "basic_binary_tree.h"
using namespace std;

int getHeight(TreeNode *node)
{
    if (node == nullptr)
        return 0;
    int leftHeight = getHeight(node->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = getHeight(node->right);
    if (rightHeight == -1)
        return -1;

    int result;
    if (abs(leftHeight - rightHeight) > 1)
        result = -1;
    else
        result = 1 + max(leftHeight, rightHeight);
    return result;
}

bool isBalanced(TreeNode *root)
{
    int result = getHeight(root);
    if (result == -1)
        return false;
    else
        return true;
}

int main()
{
    TreeNode *node9 = new TreeNode(2, nullptr, nullptr);
    TreeNode *node8 = new TreeNode(2, nullptr, nullptr);
    TreeNode *node7 = new TreeNode(2, nullptr, nullptr);
    TreeNode *node6 = new TreeNode(2, nullptr, nullptr);
    TreeNode *node5 = new TreeNode(2, nullptr, nullptr);
    TreeNode *node4 = new TreeNode(2, node9, nullptr);
    TreeNode *node3 = new TreeNode(2, node7, node8);
    TreeNode *node2 = new TreeNode(5, node5, node6);
    TreeNode *node1 = new TreeNode(4, node3, node4);
    TreeNode *root = new TreeNode(1, node1, node2);
    cout << isBalanced(root) << endl;
    return 0;
}