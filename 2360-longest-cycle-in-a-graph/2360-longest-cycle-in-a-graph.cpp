class Solution {
public:
    void dfs(int node, vector<int> &edges, int d, vector<int> &len, vector<int> &visited, int &res) {   
        if(visited[node] == false) {
            visited[node] = true;
            len[node] = d;
            if(edges[node] != -1) {
                dfs(edges[node], edges, d + 1, len, visited, res);
            }
            len[node] = -1;
        }
        else {
            if(len[node] != -1) {
                res = max(res, d - len[node]);
            }
        }
        
    }
    int longestCycle(vector<int>& edges) {
        int res = -1;
        int n = edges.size();
        vector<int> visited(n, false);
        vector<int> len(n, -1);
        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                dfs(i, edges, 0, len, visited, res);
            }
        }
        if(res == 0) return -1;
        else return res;
    }
};