#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int i) : val(i), left(nullptr), right(nullptr){};
    TreeNode(int i, TreeNode *tleft, TreeNode *tright) : val(i), left(tleft), right(tright){};
};

void print_vec(std::vector<int> &);
void print_double_vec(std::vector<std::vector<int>> &vec);
void print_stack(std::stack<TreeNode *>);

void pre_order_traversal(TreeNode *cur, std::vector<int> &vec);
void in_order_traversal(TreeNode *cur, std::vector<int> &vec);
void post_order_traversal(TreeNode *cur, std::vector<int> &vec);

std::vector<int> pre_order_traversal_iteration(TreeNode *root);
std::vector<int> in_order_traversal_iteration(TreeNode *root);
std::vector<int> post_order_traversal_iteration(TreeNode *root);
std::vector<int> level_order_traversal_iteration(TreeNode *root);
std::vector<std::vector<int>> level_order_traversal_iteration_update(TreeNode *root);

std::vector<int> traversal(TreeNode *root);
