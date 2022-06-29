// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        reverse(arr.begin(), arr.end());
        int i = 1;
        arr[0] = arr[0] + 1;
        int carry = arr[0] / 10;
        arr[0] %= 10;
        while(carry > 0 && i < N) {
            arr[i] = arr[i] + carry;
            carry = arr[i] / 10;
            arr[i] %= 10;
            i++;
        }
        if(carry > 0) arr.push_back(carry);
        reverse(arr.begin(), arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends