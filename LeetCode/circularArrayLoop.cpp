class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n; // wrap-around safely
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue; 
            
            int slow = i, fast = i;
            bool forward = nums[i] > 0; 
            
            while (true) {
                int nextSlow = nextIndex(nums, slow);
        
                int nextFast = nextIndex(nums, fast);
                if ((nums[nextFast] > 0) != forward || nums[nextFast] == 0) break;
                nextFast = nextIndex(nums, nextFast);
                
                if ((nums[nextSlow] > 0) != forward || nums[nextSlow] == 0) break;
                
                slow = nextSlow;
                fast = nextFast;
                
                if (slow == fast) {
                    if (slow == nextIndex(nums, slow)) break; 
                    return true;
                }
            }
            
            int j = i;
            int val = nums[i];
            while ((nums[j] > 0) == (val > 0) && nums[j] != 0) {
                int next = nextIndex(nums, j);
                nums[j] = 0;
                j = next;
            }
        }
        
        return false;
    }
};
