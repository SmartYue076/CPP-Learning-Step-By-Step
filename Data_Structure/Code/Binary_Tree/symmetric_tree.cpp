#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "basic_binary_tree.h"
using namespace std;

// iteration
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;
    queue<TreeNode *> q; // may different level in q, not mind, just to compare pair of two
    q.push(root->left);
    q.push(root->right);
    while (!q.empty())
    {
        TreeNode *nleft = q.front();
        q.pop();
        TreeNode *nright = q.front();
        q.pop();
        if (nleft == nullptr && nright == nullptr)
            continue;
        if (nleft == nullptr || nright == nullptr || nleft->val != nright->val)
            return false;

        q.push(nleft->left);
        q.push(nright->right);
        q.push(nleft->right);
        q.push(nright->left);
    }
    return true;
}

int main()
{
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(3, node6, nullptr);
    TreeNode *node3 = new TreeNode(3, nullptr, node5);
    TreeNode *node1 = new TreeNode(2, node3, nullptr);
    TreeNode *node2 = new TreeNode(2, nullptr, node4);
    TreeNode *root = new TreeNode(1, node1, node2);
    cout << isSymmetric(root) << endl;
    // TreeNode *new_root = invertTree(root);
    // vector<int> vec = traversal(new_root);
    // print_vec(vec);
    return 0;
}