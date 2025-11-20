class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n <= 3) return 1; 

        string s = "122";
        int head = 2; 
        while (s.size() < n) {
            char nextChar = (s.back() == '1') ? '2' : '1'; 
            int repeat = s[head] - '0'; 
            s.append(repeat, nextChar);
            head++;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') count++;
        }

        return count;
    }
};
