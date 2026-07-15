class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSums;
        prefixSums[0] = 1; // Base case: a path perfectly matching targetSum
        return dfs(root, 0, targetSum, prefixSums);
    }

private:
    int dfs(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSums) {
        if (!node) return 0;

        currentSum += node->val;
        // Check if there is a prefix path we can subtract to get targetSum
        int pathsCount = prefixSums[currentSum - targetSum];

        // Record the current prefix sum for downstream nodes
        prefixSums[currentSum]++;

        // Recurse into left and right subtrees
        pathsCount += dfs(node->left, currentSum, targetSum, prefixSums);
        pathsCount += dfs(node->right, currentSum, targetSum, prefixSums);

        // Backtrack: remove the current sum so it doesn't affect sibling branches
        prefixSums[currentSum]--;

        return pathsCount;
    }
};