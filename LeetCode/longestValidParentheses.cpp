class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);  // push index of '('
            } else {
                st.pop();    // pop the last '('
                if (st.empty()) {
                    st.push(i);  // push the index of ')'
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};
