#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with the insert function
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);

        TreeNode* curr = root;
        while (true) {
            if (val < curr->val) {
                if (curr->left)
                    curr = curr->left;
                else {
                    curr->left = new TreeNode(val);
                    break;
                }
            } else { // val > curr->val (ignoring duplicates)
                if (curr->right)
                    curr = curr->right;
                else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

// Utility: Inorder traversal to verify tree structure
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Main function to test insertIntoBST
int main() {
    Solution sol;

    // Create initial BST: 4 -> 2, 7
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    int insertVal = 5;
    root = sol.insertIntoBST(root, insertVal);

    cout << "Inorder Traversal After Insertion: ";
    inorder(root);  // Expected output: 2 4 5 7
    cout << endl;

    // Clean-up omitted for brevity
    return 0;
}
