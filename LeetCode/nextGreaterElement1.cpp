class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {
            int val = nums1[i];
            int j = 0;

            while(nums2[j] != val) {
                j++;
            }

            int nextGreater = -1;
            for(int k = j + 1; k < nums2.size(); k++) {
                if(nums2[k] > val) {
                    nextGreater = nums2[k];
                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};
