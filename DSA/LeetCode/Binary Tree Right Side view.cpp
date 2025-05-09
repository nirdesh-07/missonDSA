#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()) {
            TreeNode* rightSide = nullptr;
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (node) {
                    rightSide = node;
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }

            if (rightSide) {
                res.push_back(rightSide->val);
            }
        }

        return res;
    }
};

// Main function to test the code
int main() {
    Solution sol;

    /*
        Construct the following binary tree:
                1
               / \
              2   3
               \    \
                5    4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

