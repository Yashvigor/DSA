class Solution {
public:
    
    string process(string s) {
        stack<char> st;

        for(char c : s) {
            if(c != '#') {
                st.push(c);
            } else if(!st.empty()) {
                st.pop();
            }
        }

        string result = "";
        while(!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }

    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};
