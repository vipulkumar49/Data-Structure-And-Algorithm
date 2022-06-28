// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string S) {
        if(S.empty()) {
            return S;
        }
        string res;
        if(S[0] == S[1]) {
            res = removeConsecutiveCharacter(S.substr(1));
        }
        else {
            res = S[0] + removeConsecutiveCharacter(S.substr(1));
        }
        return res;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends