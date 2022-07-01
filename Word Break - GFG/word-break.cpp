// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool isWordBreak(string A, unordered_set<string> &s, int i, string str) {
        // Base Case
        int n = A.size();
        if(i == n) {
            if(str.empty() || s.find(str) != s.end()) return true;
            else return false;
        }
        str += A[i];
        bool res = false;
        if(s.find(str) != s.end()) {
            res = isWordBreak(A, s, i + 1, "");
        }
        if(res == true) return true;
        return isWordBreak(A, s, i + 1, str);
    }
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> s;
        string str;
        for(int i = 0; i < B.size(); i++) s.insert(B[i]);
        return isWordBreak(A, s, 0, str);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends