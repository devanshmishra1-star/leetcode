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
    bool isSameTree(TreeNode* p, TreeNode* q) {

          if (p == NULL && q == NULL)
            return true;

        // Case 2: Ek NULL hai, doosra nahi
        if (p == NULL || q == NULL)
            return false;

        // Case 3: Value different hai
        if (p->val != q->val)
            return false;

        // Case 4: Left aur Right subtree compare karo
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
    
};