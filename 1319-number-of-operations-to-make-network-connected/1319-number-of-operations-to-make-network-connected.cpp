class Solution {
public:
    void dfs(vector<int> adj[], int src, vector<bool> &visited) {
        visited[src] = true;
        for(auto i: adj[src]) {
            if(!visited[i]) {
                dfs(adj, i, visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int components = 0;
        int m = connections.size();
        if(m < n - 1) return -1;
        vector<int> adj[n];
        for(int i = 0; i < m; i++) {
            adj[connections[i][0]].push_back(connections[i][1]); 
            adj[connections[i][1]].push_back(connections[i][0]); 
        }
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(adj, i, visited);
                components++;
            }
        }
        return components - 1;
    }
};