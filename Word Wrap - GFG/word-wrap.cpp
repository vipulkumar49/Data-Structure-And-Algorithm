// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int getCost(vector<int> &nums, int k, int width, int i, vector<vector<int>> &dp) {
        int n = nums.size();
        // cout << width << "\n";
        if(i == n - 1)  {
            if(nums[i] >= width) {
                return dp[i][width] = (width) * (width);
            }
            else {
                return dp[i][width] = 0;
            }
        }
        if(dp[i][width] != -1) return dp[i][width];
        int res = INT_MAX;
        if(nums[i] >= width) {
            int cost = (width) * (width);
            res = cost + getCost(nums, k, k - nums[i], i + 1, dp);
        }
        else {
            int cost = (width) * (width);
            res = cost + getCost(nums, k, k - nums[i], i + 1, dp);
            res = min(res, getCost(nums, k, width == k ? width - nums[i] : width - nums[i] - 1, i + 1, dp));
        }
        return dp[i][width] = res;
    }
    int solveWordWrap(vector<int>nums, int k) { 
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return getCost(nums, k, k, 0, dp);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends