#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#include "basic_binary_tree.h"
using namespace std;

inline string vec_process(const vector<int> &ivec)
{
    string result;
    int size = ivec.size();
    if (size == 0)
        return "";
    else if (size == 1)
        return to_string(ivec[0]);
    else
    {
        for (int i = 0; i < size - 1; i++)
            result += to_string(ivec[i]) + "->";
        result += to_string(ivec[size - 1]);
        return result;
    }
}

void getVector(TreeNode *node, vector<int> &ivec, vector<string> &svec)
{
    ivec.push_back(node->val);
    if (node->left == nullptr && node->right == nullptr) // leaf
    {
        svec.push_back(vec_process(ivec));
        return;
    }

    if (node->left != nullptr)
    {
        getVector(node->left, ivec, svec);
        ivec.pop_back();
    }
    if (node->right != nullptr)
    {
        getVector(node->right, ivec, svec);
        ivec.pop_back();
    }
    return;
}

vector<string> binaryTreePaths(TreeNode *root)
{
    if (root == nullptr)
        return {""};
    vector<int> ivec;
    vector<string> svec;
    getVector(root, ivec, svec);
    return svec;
}

void print_vector(const vector<string> &vec)
{
    for (auto ele : vec)
        cout << ele << endl;
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
    vector<string> vec = binaryTreePaths(root);
    print_vector(vec);
    return 0;
}