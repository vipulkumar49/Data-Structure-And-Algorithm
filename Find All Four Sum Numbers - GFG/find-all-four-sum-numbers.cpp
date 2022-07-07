// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int p = i + 1, q = j - 1;
                while(p < q) {
                    long long sum = arr[i] + arr[j] + arr[p] + arr[q];
                    if(sum == k) {
                        vector<int> v = {arr[i], arr[j], arr[p], arr[q]};
                        sort(v.begin(), v.end());
                        res.push_back(v);
                        p++, q--;
                    }
                    else if(sum < k) {
                        p++;
                    }
                    else {
                        q--;
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        auto it = unique(res.begin(), res.end());
        res.resize(distance(res.begin(), it));
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends