class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, bal = 0;
        for(int i = 0; i < s.size(); i++) {
            bal += s[i] == '(' ? 1: -1;
            if(bal == -1) {
                ans++;
                bal++;
            }
        }
        return ans + bal;
    }
};