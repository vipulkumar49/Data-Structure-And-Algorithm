// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    vector<int> dx = {1, 1, 1, 0, 0, -1, -1, -1};
    vector<int> dy = {-1, 1, 0, -1, 1, -1, 1, 0};
    
    void DFS(vector<vector<int>> &grid, int i, int j, int &count) {
        int n = grid.size(), m = grid[0].size();
        grid[i][j] = -1;
        for(int k = 0; k < 8; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                count++;
                DFS(grid, x, y, count);
            }
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int result = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int cnt = 1;
                    DFS(grid, i, j, cnt);
                    result = max(cnt, result); 
                } 
            }
        }
        return result;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends