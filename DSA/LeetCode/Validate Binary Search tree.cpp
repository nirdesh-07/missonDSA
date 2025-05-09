#include <iostream>
#include <climits>
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
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);        
    }

private:
    bool valid(TreeNode* node, long minimum, long maximum) {
        if (!node) return true;

        if (!(node->val > minimum && node->val < maximum)) return false;

        return valid(node->left, minimum, node->val) &&
               valid(node->right, node->val, maximum);
    }    
};

// Utility function to test
int main() {
    Solution sol;

    // Construct a valid BST:
    //       5
    //      / \.
    //     3   7
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    cout << (sol.isValidBST(root) ? "Valid BST" : "Invalid BST") << endl;

    // Add violation to test invalid case:
    root->right->left = new TreeNode(4); // 4 is less than 5, invalid in right subtree

    cout << (sol.isValidBST(root) ? "Valid BST" : "Invalid BST") << endl;

    // Clean-up omitted for brevity
    return 0;
}
