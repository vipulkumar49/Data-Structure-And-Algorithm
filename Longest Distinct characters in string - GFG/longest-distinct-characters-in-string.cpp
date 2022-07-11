// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string S) {
    int n = S.size();
    int ws = 0, we = 0;
    map<char, int> cnt;
    int len = 1;
    while(we < n) {
        cnt[S[we]]++;
        while(ws <= we && cnt[S[we]] > 1) {
            cnt[S[ws]]--;
            ws++;
        }
        we++;
        len = max(len, we - ws);
    }
    return len;
}