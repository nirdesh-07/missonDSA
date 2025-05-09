#include <iostream>
#include <vector>
#include <string>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* node, string path, vector<string>& res) {
        if (!node) return;
        path += to_string(node->val);
        if (!node->left && !node->right) {
            res.push_back(path);
        } else {
            path += "->";
            dfs(node->left, path, res);
            dfs(node->right, path, res);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};

// Example test function
int main() {
    // Build the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution s;
    vector<string> paths = s.binaryTreePaths(root);

    cout << "Binary Tree Paths:\n";
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
