// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N) {
        int len = INT_MAX;
        for(int i = 0; i < N; i++) len = min(len, (int)arr[i].length());
        string prefix = "";
        for(int j = 0; j < len; j++) {
            char ch = arr[0][j];
            for(int i = 1; i < N; i++) {
                if(arr[i][j] != ch) {
                    if(prefix.empty()) return "-1";
                    else return prefix;
                }
            }
            prefix += ch;
        }
        if(prefix.empty()) return "-1";
        else return prefix;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends