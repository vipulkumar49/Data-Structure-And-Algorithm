// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n) {
    vector<int> se(n);
    set<int> s;
    for(int i = 0; i < n; i++) {
        auto lb = s.lower_bound(arr[i]);
        if(lb == s.begin()) se[i] = -1;
        else {
            lb--;
            se[i] = *lb;
        }
        s.insert(arr[i]);
    }
    return se;
}