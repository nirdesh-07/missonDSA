#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>       // for abs
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    using node2 = tuple<TreeNode*, TreeNode*, bool>; // Node, Parent, Visited flag

    static int distributeCoins(TreeNode* root) {
        if (!root) return 0;
        vector<node2> stack = {make_tuple(root, nullptr, false)};
        int moves = 0;

        while (!stack.empty()) {
            TreeNode* node;
            TreeNode* parent;
            bool visited;

            tie(node, parent, visited) = stack.back(); // use std::tie
            stack.pop_back();

            if (!visited) {
                stack.push_back(make_tuple(node, parent, true)); // mark as visited
                if (node->right)
                    stack.push_back(make_tuple(node->right, node, false));
                if (node->left)
                    stack.push_back(make_tuple(node->left, node, false));
            } else {
                int excess = node->val - 1;
                if (parent)
                    parent->val += excess;
                moves += abs(excess);
            }
        }

        return moves;
    }
};

int main() {
    // Example: Tree with 3->0->0
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);

    int result = Solution::distributeCoins(root);
    cout << "Minimum moves required: " << result << endl;

    // Clean up
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
