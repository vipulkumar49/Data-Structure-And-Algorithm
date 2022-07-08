class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    int getMinCut(string &s, int i, int n, vector<int> &dp) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int minCut = INT_MAX;
        for(int j = i; j < n; j++) {
            if(isPalindrome(s, i, j)) {
                int cut = 1 + getMinCut(s, j + 1, n, dp);
                minCut = min(cut, minCut);
            }
        }
        return dp[i] = minCut;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return getMinCut(s, 0, n, dp)  - 1;
    }
};