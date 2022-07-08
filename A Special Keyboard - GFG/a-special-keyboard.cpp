// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        map<int, int> mp;
        int n = S1.size();
        for(int i = 0; i < n; i++) {
            mp[S1[i]] = i;
        }
        int pos = 0, ans = 0;
        int m = S2.size();
        for(int i = 0; i < m; i++) {
            ans += abs(mp[S2[i]] - pos);
            pos = mp[S2[i]];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends