// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int getEditDistance(int i, int j, string s, string t, vector<vector<int>> &dp) {
        int n = s.size(), m = t.size();
        if(i == n || j == m) return max(n - i, m - j);
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = getEditDistance(i + 1, j + 1, s, t, dp);
        else return dp[i][j] = 1 + min({getEditDistance(i + 1, j, s, t, dp), getEditDistance(i + 1, j + 1, s, t, dp), getEditDistance(i, j + 1, s, t, dp)});
        
    }
    int editDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return getEditDistance(0, 0, s, t, dp);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends