class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        vector<bool> used(m, false); // to track if a basket is already used
        int unplaced = 0;

        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < m; j++) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;  // mark this basket as used
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                unplaced++; // if no suitable basket found
            }
        }

        return unplaced;
    }
};
