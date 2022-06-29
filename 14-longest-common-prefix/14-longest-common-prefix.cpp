class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int len = 0;
        for(int i = 0; i < n; i++) len = max(len, (int)strs[i].length());
        string prefix = "";
        for(int j = 0; j < len; j++) {
            char ch = strs[0][j];
            for(int i = 1; i < n; i++) {
                if(strs[i][j] != ch) {
                    return prefix;
                }
            }
            prefix += ch;
        }
        return prefix;
    }
};