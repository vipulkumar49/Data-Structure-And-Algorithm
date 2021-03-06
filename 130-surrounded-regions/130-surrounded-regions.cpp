class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') {
                q.push({i, 0});
            }
            if(board[i][m - 1] == 'O') {
                q.push({i, m - 1});
            }
        }
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') {
                q.push({0, j});
            }
            if(board[n - 1][j] == 'O') {
                q.push({n - 1, j});
            }
        }
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            board[x][y] = '#';
            for(int i = 0; i < 4; i++) {
                int X = x + dx[i];
                int Y = y + dy[i];
                if(X >= 0 && Y >= 0 && X < n && Y < m && board[X][Y] == 'O') { 
                   q.push({X, Y});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};