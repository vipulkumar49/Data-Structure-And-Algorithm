// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k) {
        unordered_map<int, int> count;
        vector<int> res;
        if(k > n) return res;
        int we = 0, ws = 0;
        int distinct = 0;
        while(we < n) {
            count[A[we]]++;
            if(count[A[we]] == 1) distinct++;
            we++;
            if(we - ws == k) {
                res.push_back(distinct);
                count[A[ws]]--;
                if(count[A[ws]] == 0) distinct--;
                ws++;
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

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends