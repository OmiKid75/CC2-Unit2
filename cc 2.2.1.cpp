#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if (left != nullptr && right != nullptr) {
            return root;
        }
        return left != nullptr ? left : right;
    }
};

int main() {
    // Constructing a sample binary tree:
    //         3
    //       /   \
    //      5     1
    //     / \   / \
    //    6   2 0   8
    //       / \
    //      7   4

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution solution;

    // Test case 1: LCA of node 5 and node 1 should be root (3)
    TreeNode* p1 = root->left;     // Node 5
    TreeNode* q1 = root->right;    // Node 1
    TreeNode* lca1 = solution.lowestCommonAncestor(root, p1, q1);
    std::cout << "LCA of 5 and 1: " << (lca1 ? std::to_string(lca1->val) : "NULL") << std::endl;

    // Test case 2: LCA of node 5 and node 4 should be node 5
    TreeNode* p2 = root->left;             // Node 5
    TreeNode* q2 = root->left->right->right; // Node 4
    TreeNode* lca2 = solution.lowestCommonAncestor(root, p2, q2);
    std::cout << "LCA of 5 and 4: " << (lca2 ? std::to_string(lca2->val) : "NULL") << std::endl;

    // Clean up dynamically allocated memory (optional for demo)
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}