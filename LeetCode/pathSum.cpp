class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        int newSum = targetSum - root->val;

        return hasPathSum(root->left, newSum) ||
               hasPathSum(root->right, newSum);
    }
};
