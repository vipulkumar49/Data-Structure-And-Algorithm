// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        long long mod = 1e9 + 7;
        if(n == 1) return k % mod;
        long long same = k % mod;
        long long diff = ((k % mod) * ((k - 1) % mod)) % mod;
        long long total = (same + diff) % mod;
        for(int i = 3; i <= n; i++) {
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