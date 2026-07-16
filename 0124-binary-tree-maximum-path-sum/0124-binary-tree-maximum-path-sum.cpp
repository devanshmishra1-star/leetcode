/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int global_max;

    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        // Recursively get the maximum gain from left and right subtrees.
        // If a subtree returns a negative sum, we ignore it (take 0).
        int leftGain = max(0, maxGain(node->left));
        int rightGain = max(0, maxGain(node->right));

        // Price of the path starting at this node and splitting left + right
        int currentPathSum = node->val + leftGain + rightGain;

        // Update the global maximum path sum
        global_max = max(global_max, currentPathSum);

        // Return the maximum gain this node can pass to its parent
        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        global_max = INT_MIN;
        maxGain(root);
        return global_max;
    }
};