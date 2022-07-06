class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row, column;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    row.push_back(i);
                    column.push_back(j);
                }
            }
        }
        for(int i = 0; i < row.size(); i++) {
            for(int j = 0; j < m; j++) {
                matrix[row[i]][j] = 0;
            }
        }
        for(int j = 0; j < column.size(); j++) {
            for(int i = 0; i < n; i++) {
                matrix[i][column[j]] = 0;
            }
        }
    }
};