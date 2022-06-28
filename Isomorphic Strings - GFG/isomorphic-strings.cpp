// { Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2) {
        map<char, char> mp1, mp2;
        int n1 = str1.size(), n2 = str2.size();
        if(n1 != n2) return false;
        for(int i = 0; i < n1; i++) {
            if(mp1.find(str1[i]) != mp1.end()) {
                if(mp1[str1[i]] != str2[i]) {
                    return false;
                }
            }
            mp1[str1[i]] = str2[i];
        }
        for(int i = 0; i < n1; i++) {
            if(mp2.find(str2[i]) != mp2.end()) {
                if(mp2[str2[i]] != str1[i]) {
                    return false;
                }
            }
            mp2[str2[i]] = str1[i];
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends