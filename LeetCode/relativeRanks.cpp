class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted = score;
        sort(sorted.begin(), sorted.end(), greater<int>());
        
        vector<string> ans;
        
        for (int s : score) {
            int rank = find(sorted.begin(), sorted.end(), s) - sorted.begin();
            
            if (rank == 0) ans.push_back("Gold Medal");
            else if (rank == 1) ans.push_back("Silver Medal");
            else if (rank == 2) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(rank+1));
        }
        
        return ans;
    }
};
