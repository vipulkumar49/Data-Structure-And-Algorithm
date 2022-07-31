class Solution {
public:
    void dfs(vector<int> &edges, int node, vector<int> &len, int d, vector<int> &visited, int &res) {
        if(visited[node] == true) {
            if(len[node] != -1)
                res = max(res, d - len[node]);
        }
        else {
            visited[node] = true; 
            len[node] = d;
            if(edges[node] != -1)
                dfs(edges, edges[node], len, d + 1, visited, res);
            len[node] = -1;
        }
    }
    int longestCycle(vector<int>& edges) {
        int res = -1;
        int n = edges.size();
        vector<int> visited(n, false);
        vector<int> len(n, -1);
        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                dfs(edges, i, len, 0, visited, res);
            }
        }
        return res;
    }
};