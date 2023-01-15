#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include "basic_binary_tree.h"
using namespace std;

int getCount(TreeNode *node)
{
    if (node == nullptr)
        return 0;
    int left_depth = 0;
    int right_depth = 0;
    TreeNode *cur = node;
    while (cur != nullptr)
    {
        left_depth++;
        cur = cur->left;
    }
    while (cur != nullptr)
    {
        right_depth++;
        cur = cur->right;
    }
    if (left_depth == right_depth)
        return pow(2, left_depth) - 1;

    int left_count = getCount(node->left);
    int right_count = getCount(node->right);
    return 1 + left_count + right_count;
}

int countNodes(TreeNode *root)
{
    return getCount(root);
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
    cout << countNodes(root) << endl;
    return 0;
}