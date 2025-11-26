class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;  
        return solve(0, s, dict, memo);
    }

    vector<string> solve(int start, string &s, unordered_set<string> &dict,
                         unordered_map<int, vector<string>> &memo) {
        
        if (memo.count(start)) return memo[start];
        vector<string> result;

        if (start == s.size()) {
            result.push_back("");
            return result;
        }

        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);

            if (dict.count(word)) {
                vector<string> sublist = solve(end, s, dict, memo);

                for (string sub : sublist) {
                    string space = sub.empty() ? "" : " ";
                    result.push_back(word + space + sub);
                }
            }
        }

        memo[start] = result;
        return result;
    }
};
