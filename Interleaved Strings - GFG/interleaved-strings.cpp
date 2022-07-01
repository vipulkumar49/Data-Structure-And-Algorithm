// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool getInterleave(string A, string B, string C, int i, int j, int k, vector<vector<vector<int>>> &dp) {
        int n = A.length(), m = B.length();
        if(k == n + m) {
            return true;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        bool res = false;
        if(A[i] == C[k]) res = getInterleave(A, B, C, i + 1, j, k + 1, dp);
        if(res == true) return dp[i][j][k] = true;
        
        if(B[j] == C[k]) res = getInterleave(A, B, C, i, j + 1, k + 1, dp);
        if(res == true) return dp[i][j][k] = true;
        else return dp[i][j][k] = false;
    }
    bool isInterleave(string A, string B, string C) {
        int n = A.length(), m = B.length();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(n + m + 1, - 1)));
        if(getInterleave(A, B, C, 0, 0, 0, dp)) return true;
        else return false;
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends