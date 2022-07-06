// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
    	// Sort based on arrival time
    	vector<pair<int, int>> time(n);
    	for(int i = 0; i < n; i++) {
    	    time[i].first = arr[i];
    	    time[i].second = dep[i];
    	}
    	sort(time.begin(), time.end());
    	int platforms = 1;
    	priority_queue<int, vector<int>, greater<int>> pq;
    	pq.push(time[0].second);
    	for(int i = 1; i < n; i++) {
    	    if(pq.top() >= time[i].first) 
    	        platforms++;
    	    else 
    	        pq.pop();
    	        
    	    pq.push(time[i].second);
    	}
        return platforms;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends