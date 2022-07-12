// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}// } Driver Code Ends


string firstRepChar(string s) {
    int n = s.size();
    map<char, int> ch;
    for(int i = 0; i < n; i++) {
        if(ch[s[i]] == 1) {
            string str = "";
            str += s[i];
            return str;
        }
        ch[s[i]]++;
    }
    return "-1";
}