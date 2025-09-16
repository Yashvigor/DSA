class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = 0;
        int groups = n / 3;
        
        // Start from the second-last element and go backwards, jumping two positions each time.
        for (int i = n - 2; groups > 0; i -= 2, groups--) {
            sum += nums[i];
        }
        
        return sum;
    }
};
