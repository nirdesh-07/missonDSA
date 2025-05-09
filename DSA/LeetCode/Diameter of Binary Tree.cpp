#include <iostream>
#include <algorithm>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int res = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;        
    }

private:
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int l = dfs(root->left); // depth of left subtree
        int r = dfs(root->right); // depth of right subtree

        res = std::max(res, l + r); // update the diameter

        return 1 + std::max(l, r); // return the depth of the current node
    }    
};

// Example test function
int main() {
    // Build the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    int diameter = s.diameterOfBinaryTree(root);

    cout << "Diameter of the Binary Tree: " << diameter << endl;

    return 0;
}
