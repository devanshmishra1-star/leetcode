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
public:
    int maxDepth(TreeNode* root) {
             // Base Case
        if (root == NULL)
            return 0;

        // Left subtree ki depth
        int left = maxDepth(root->left);

        // Right subtree ki depth
        int right = maxDepth(root->right);

        // Current node + maximum depth
        return  max(left, right)+1;
                
         
        
    }
};