class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        TreeNode* queue[10000]; 
        int front = 0, rear = 0;
        queue[rear++] = root;

        while(front < rear) {
            int levelSize = rear - front;
            int levelArr[1000]; 
            int idx = 0;

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = queue[front++];
                levelArr[idx++] = node->val;

                if(node->left) queue[rear++] = node->left;
                if(node->right) queue[rear++] = node->right;
            }

            vector<int> level;
            for(int i = 0; i < idx; i++)
                level.push_back(levelArr[i]);

            ans.push_back(level);
        }

        return ans;
    }
};
