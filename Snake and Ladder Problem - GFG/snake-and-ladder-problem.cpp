// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        unordered_map<int, int> snakeLadder;
        for(int i = 0; i < N; i++) {
            snakeLadder[arr[2 * i]] = arr[2 * i + 1];
        }
        
        vector<bool> visited(31, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int p = q.front();
                q.pop();
                if(p == 30) return level;
                for(int j = 1; j <= 6; j++) {
                    int r = p + j;
                    if(r <= 30 && !visited[r]) {
                        if(snakeLadder.find(r) != snakeLadder.end()) {
                            q.push(snakeLadder[r]);
                            visited[snakeLadder[r]] = true;
                        }
                        else {
                            q.push(r);
                            visited[r] = true;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends