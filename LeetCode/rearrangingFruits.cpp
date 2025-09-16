class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;
        map<int, int> count1, count2;
        for (int x : basket1) {
            freq[x]++;
            count1[x]++;
        }
        for (int x : basket2) {
            freq[x]++;
            count2[x]++;
        }

     // Checking if making the baskets equal is possible
        for (auto& [val, f] : freq) {
            if (f % 2 != 0) return -1;
        }

    // Collecting extra elements in each basket
        vector<int> extra1, extra2;
        for (auto& [val, _] : freq) {
            int diff = count1[val] - count2[val];
            if (diff > 0) {
                for (int i = 0; i < diff / 2; ++i)
                    extra1.push_back(val);
            } else if (diff < 0) {
                for (int i = 0; i < -diff / 2; ++i)
                    extra2.push_back(val);
            }
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend()); // descending

        int minElement = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < extra1.size(); ++i) {
            cost += min(2 * minElement, min(extra1[i], extra2[i]));
        }

        return cost;
    }
};
