class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while(n > 1) {
            string t;
            int cnt = 1;
            for(int i = 0; i <= s.length() - 1; i++) {
                if(s[i] == s[i + 1]) {
                    cnt++;
                }
                else {
                    t += to_string(cnt);
                    t += s[i];
                    cnt = 1;
                }
            }
            s = t;
            n -= 1;
        }
        return s;
    }
};