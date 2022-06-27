// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        long long total = k;
        // same - prev two fence have same color
        // diff - prev two fence have diff color
        long long same = 0;
        long long diff = k;
        long long mod = 1e9 + 7;
        for(int i = 2; i <= n; i++) {
            same = diff % mod;
            diff = ((total) % mod * (k - 1) % mod) % mod;
            total = ((same) % mod + (diff) % mod) % mod;
        }
        return total;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends