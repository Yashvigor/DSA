class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int pivot = nums[right];
            int i = left;
            for (int j = left; j < right; j++) {
                if (nums[j] <= pivot) {
                    swap(nums[i], nums[j]);
                    i++;
                }
            }
            swap(nums[i], nums[right]); 

            int count = nums.size() - i; 

            if (count == k) return nums[i];      
            else if (count > k) left = i + 1;   
            else right = i - 1;                 
        }

        return -1; 
    
    }
};
