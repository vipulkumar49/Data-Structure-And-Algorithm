// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	    void getAllString(string s, vector<string> &res, string output, int i) {
	        int n = s.size();
	        if(i == n) {
	            res.push_back(output);
	            return;
	        }
	        // do not include character 
	        getAllString(s, res, output, i + 1);
	        // include the charcater
	        getAllString(s, res, output + s[i], i + 1);
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string> res;
		    string output;
		    getAllString(s, res, output, 0);
		    sort(res.begin(), res.end());
		    res.erase(res.begin());
		    return res;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends