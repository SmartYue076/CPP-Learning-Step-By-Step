#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "basic_binary_tree.h"
using namespace std;

// recursion
TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

// // iteration
// TreeNode *invertTree(TreeNode *root)
// {
//     stack<TreeNode *> st;
//     if (root == nullptr)
//         return root;
//     st.push(root);
//     while (!st.empty())
//     {
//         TreeNode *cur = st.top();
//         st.pop();
//         swap(cur->left, cur->right);
//         if (cur->left)
//             st.push(cur->left);
//         if (cur->right)
//             st.push(cur->right);
//     }
//     return root;
// }

int main()
{
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node4 = new TreeNode(4, nullptr, node6);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node1 = new TreeNode(1, node3, node4);
    TreeNode *node2 = new TreeNode(2, node5, nullptr);
    TreeNode *root = new TreeNode(0, node1, node2);
    TreeNode *new_root = invertTree(root);
    vector<int> vec = traversal(new_root);
    print_vec(vec);
    return 0;
}