class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int bit = 0; bit < 32; bit++) {
            int count = 0;

            for (int n : nums) {
                if (n & (1 << bit)) {
                    count++;
                }
            }

            if (count % 3 != 0) {
                result |= (1 << bit);
            }
        }

        return result;
    }
};
