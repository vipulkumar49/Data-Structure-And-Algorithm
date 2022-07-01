class Solution {
public:
    bool checkInterleave(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp) {
        int n = s1.size(), m = s2.size();
        if(i == n && j == m) return true;
        if(dp[i][j] != -1) return dp[i][j];
        bool res = false;
        if(s1[i] == s3[k]) res = checkInterleave(s1, s2, s3, i + 1, j, k + 1, dp);
        if(res == true) return dp[i][j] = true;
        if(s2[j] == s3[k]) res = checkInterleave(s1, s2, s3, i, j + 1, k + 1, dp); 
        if(res == true) return dp[i][j] = true;
        else  return dp[i][j] = false; 
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return false;
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return checkInterleave(s1, s2, s3, 0, 0, 0, dp);
    }
};