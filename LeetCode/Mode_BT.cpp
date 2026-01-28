class Solution {
public:
    vector<int> values; 

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        values.push_back(root->val);
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root); 
        sort(values.begin(), values.end());  
        
        vector<int> result;
        int maxFreq = 0;
        int count = 0;
        int prev = values.empty() ? 0 : values[0] - 1; 

        for (int val : values) {
            if (val == prev) {
                count++;
            } else {
                count = 1;
                prev = val;
            }
            
            if (count > maxFreq) {
                maxFreq = count;
                result.clear();
                result.push_back(val);
            } else if (count == maxFreq) {
                result.push_back(val);
            }
        }

        return result;
    }
};
