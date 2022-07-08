class Solution {
public:
    void union_set(int a, int b, vector<int> &parent, vector<int> &rank) {
        if(rank[a] > rank[b]) {
            parent[b] = a;
        }
        else if(rank[b] > rank[a]) {
            parent[a] = b;
        }
        else {
            parent[b] = a;
            rank[a] += 1; 
        }
    }
    int find_set(int v, vector<int> &parent) {
        if(parent[v] == v) {
            return v;
        }
        return parent[v] = find_set(parent[v], parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n - 1) return -1;
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for(int i = 0; i < m; i++) {
            union_set(find_set(connections[i][0], parent), find_set(connections[i][1], parent), parent, rank);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(parent[i] == i) ans++;
        }
        return ans - 1;
    }
};