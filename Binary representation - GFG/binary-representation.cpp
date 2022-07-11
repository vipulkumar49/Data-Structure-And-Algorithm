// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    string getBinaryRep(int N)
    {
        string res(30, '0');
        for(int i = 29; i >= 0; i--) {
            if((N & (1 << i))) {
                res[29 - i] = '1';
            }
            else {
                res[29 - i] = '0';
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
       
        Solution ob;
        string ans = ob.getBinaryRep(N);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends