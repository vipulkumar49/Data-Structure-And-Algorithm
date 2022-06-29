// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    vector<int> dx = {-1, -1, -1, 1, 1, 1, 0, 0};
    vector<int> dy = {0, -1, 1, 0, -1, 1, -1, 1};
    bool isSafe(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited) {
        int n = grid.size(), m = grid[0].size();
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j]  && !visited[i][j]) {
            return true;
        }
        return false;
    }
    void DFS(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, int &count) {
        visited[i][j] = true;
        for(int k = 0; k < 8; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(isSafe(grid, x, y, visited)) {
                count++;
                DFS(grid, x, y, visited, count);
            }
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int res = INT_MIN;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    int count = 1;
                    DFS(grid, i, j, visited, count);
                    res = max(res, count);
                }
            }
        }
        return res;
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