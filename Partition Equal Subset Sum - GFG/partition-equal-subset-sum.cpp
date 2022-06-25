// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int getEqualPartition(int *arr, int N, int target, vector<vector<int>> &dp) {
        if(target == 0) return 1;
        
        if(N == 0) return 0;
        if(dp[N][target] != -1) return dp[N][target];
        if(arr[N - 1] > target) return getEqualPartition(arr, N - 1, target, dp);
        return dp[N][target] = getEqualPartition(arr, N - 1, target, dp) || getEqualPartition(arr, N - 1, target - arr[N - 1], dp);
    }
    int equalPartition(int N, int arr[]) {
        int sum = 0, total = 0;
        for(int i = 0; i < N; i++) {
            total += arr[i];
        }
        if(total % 2 == 0) {
            int target = total / 2;
            vector<vector<int>> dp(N + 1, vector<int>(target + 1, - 1));
            int res = getEqualPartition(arr, N, target, dp);
            return res; 
        }
        else {
            return 0;
        }
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends