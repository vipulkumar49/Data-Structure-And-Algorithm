class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) 
            return 1;
        m = m - 1;
        n = n - 1;
        long long res = 1;
        int j = 1;
        for(int i = m + 1; i <= m + n; i++) {
            res *= i;
            res /= j;
            j++;
        }
        return res;
    }
};