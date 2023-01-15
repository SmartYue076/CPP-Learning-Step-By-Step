#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include "basic_binary_tree.h"
using namespace std;

void pre_order_traversal(TreeNode *cur, vector<int> &vec)
{
    if (cur == nullptr)
        return;
    vec.push_back(cur->val);
    pre_order_traversal(cur->left, vec);
    pre_order_traversal(cur->right, vec);
}

void in_order_traversal(TreeNode *cur, vector<int> &vec)
{
    if (cur == nullptr)
        return;
    in_order_traversal(cur->left, vec);
    vec.push_back(cur->val);
    in_order_traversal(cur->right, vec);
}

void post_order_traversal(TreeNode *cur, vector<int> &vec)
{
    if (cur == nullptr)
        return;
    post_order_traversal(cur->left, vec);
    post_order_traversal(cur->right, vec);
    vec.push_back(cur->val);
}

vector<int> pre_order_traversal_iteration(TreeNode *root)
{
    vector<int> vec;
    if (root == nullptr)
        return vec;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *ele = st.top();
        vec.push_back(ele->val);
        st.pop();
        if (ele->right != nullptr) // note: right then left for order
            st.push(ele->right);
        if (ele->left != nullptr)
            st.push(ele->left);
    }
    return vec;
}

vector<int> in_order_traversal_iteration(TreeNode *root)
{
    vector<int> vec;
    if (root == nullptr)
        return vec;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    st.push(root);
    while (!st.empty() && cur != nullptr)
    {
        if (cur->left == nullptr)
        {
            TreeNode *ele = st.top();
            vec.push_back(ele->val);
            st.pop();
            if (ele->right != nullptr)
            {
                st.push(ele->right);
                cur = ele->right;
            }
        }
        else
        {
            cur = cur->left;
            st.push(cur);
        }
    }
    return vec;
}

vector<int> post_order_traversal_iteration(TreeNode *root)
{
    vector<int> vec;
    if (root == nullptr)
        return vec;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *ele = st.top();
        vec.push_back(ele->val);
        st.pop();
        if (ele->left != nullptr)
            st.push(ele->left);
        if (ele->right != nullptr)
            st.push(ele->right);
    }
    reverse(vec.begin(), vec.end());
    return vec;
}

vector<int> level_order_traversal_iteration(TreeNode *root)
{
    vector<int> vec;
    if (root == nullptr)
        return vec;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *ele = q.front();
        vec.push_back(ele->val);
        q.pop();
        if (ele->left != nullptr)
            q.push(ele->left);
        if (ele->right != nullptr)
            q.push(ele->right);
    }
    return vec;
}

vector<vector<int>> level_order_traversal_iteration_update(TreeNode *root)
{
    vector<vector<int>> vec;
    if (root == nullptr)
        return vec;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> sub_vec;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *ele = q.front();
            sub_vec.push_back(ele->val);
            q.pop();
            if (ele->left != nullptr)
                q.push(ele->left);
            if (ele->right != nullptr)
                q.push(ele->right);
        }
        vec.push_back(sub_vec);
    }
    return vec;
}

vector<int> traversal(TreeNode *root)
{
    vector<int> vec;
    pre_order_traversal(root, vec);
    return vec;
}

void print_vec(vector<int> &vec)
{
    for (int ele : vec)
        cout << ele << "\t";
    cout << endl;
}

void print_double_vec(vector<vector<int>> &vec)
{
    for (vector<int> sub_vec : vec)
    {
        for (int ele : sub_vec)
            cout << ele << "\t";
        cout << endl;
    }
    cout << endl;
}

void print_stack(stack<TreeNode *> st)
{
    stack<TreeNode *> c_st(st);
    while (!c_st.empty())
    {
        TreeNode *ele = c_st.top();
        cout << ele->val << " ";
        c_st.pop();
    }
    cout << endl;
}

void print_queue(queue<TreeNode *> q)
{
    queue<TreeNode *> c_st(q);
    while (!c_st.empty())
    {
        TreeNode *ele = c_st.front();
        cout << ele->val << " ";
        c_st.pop();
    }
    cout << endl;
}

// int main()
// {
//     TreeNode *node3 = new TreeNode(3);
//     TreeNode *node4 = new TreeNode(4);
//     TreeNode *node5 = new TreeNode(5);
//     TreeNode *node1 = new TreeNode(1, node3, node4);
//     TreeNode *node2 = new TreeNode(2, node5, nullptr);
//     TreeNode *node = new TreeNode(0, node1, node2);
//     vector<vector<int>> vec = level_order_traversal_iteration_update(node);
//     print_double_vec(vec);
//     return 0;
// }
