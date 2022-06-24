// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int MCM(int *arr, int i, int j, vector<vector<int>> &dp) {
        if(i == j) return 0;
        int mn = INT_MAX, cost = 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i; k < j; k++) {
            cost = MCM(arr, i, k, dp) + MCM(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
            mn = min(cost, mn);
        }
        return dp[i][j] = mn;
    }
    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return MCM(arr, 1, N - 1, dp);    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends