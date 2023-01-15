#include <iostream>
#include <queue>
#include "basic_binary_tree.h"
using namespace std;

void getSum(TreeNode *node, bool is_left, int &sum)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        if (is_left)
            sum += node->val;
        return;
    }

    if (node->left != nullptr)
        getSum(node->left, true, sum);
    if (node->right != nullptr)
        getSum(node->right, false, sum);
    return;
}

int sumOfLeftLeaves(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    if ((root->left == nullptr) && (root->right == nullptr))
        return root->val;
    int sum = 0;
    getSum(root, false, sum);
    return sum;
}

int main()
{
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);
    TreeNode *node2 = new TreeNode(20, node3, node4);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *root = new TreeNode(1, node1, node2);
    cout << sumOfLeftLeaves(root) << endl;
    return 0;
}