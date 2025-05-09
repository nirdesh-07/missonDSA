#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void generatePaths(TreeNode* root, vector<string>& ans, string temp) {
        if (!root)
            return;

        if (!root->left && !root->right) {
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }

        temp += to_string(root->val) + "->";
        generatePaths(root->left, ans, temp);
        generatePaths(root->right, ans, temp);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        generatePaths(root, ans, "");
        return ans;
    }
};

// Example usage
int main() {
    // Construct binary tree:
    //     1
    //    / \
    //   2   3
    //    \
    //     5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<string> paths = sol.binaryTreePaths(root);

    cout << "Binary Tree Paths:\n";
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
