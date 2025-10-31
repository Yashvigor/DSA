class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string prefix = "";
        for (string& w : words) {
            prefix += w;
            if (prefix == s) return true;      
            if (prefix.size() > s.size()) break; 
        }
        return false;
    }
};
