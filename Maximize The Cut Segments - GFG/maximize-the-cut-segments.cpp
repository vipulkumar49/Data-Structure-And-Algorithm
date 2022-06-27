// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximumCuts(int n, int x, int y, int z, vector<int> &dp) {
        if(n < 0) return INT_MIN;
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int a = maximumCuts(n - x, x, y, z, dp);
        int b = maximumCuts(n - y, x, y, z, dp);
        int c = maximumCuts(n - z, x, y, z, dp);
        int res = max({a, b, c});
        if(res == INT_MIN) return dp[n] = INT_MIN;
        else return dp[n] = 1 + res;
    }
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1);
        int res = maximumCuts(n, x, y, z, dp);
        if(res == INT_MIN) return 0;
        else return res;
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends