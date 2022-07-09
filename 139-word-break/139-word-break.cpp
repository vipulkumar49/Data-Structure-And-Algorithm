class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        unordered_set<string> word(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j] == true && word.find(s.substr(j, i - j)) != word.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};