class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(verticalCuts.begin(), verticalCuts.end());
        sort(horizontalCuts.begin(), horizontalCuts.end());
        int max_w = 0, max_h = 0;
        long long mod = 1e9 + 7;
        int n = horizontalCuts.size();
        for(int i = 0; i < n; i++) {
            if(i == 0) max_h = max(max_h, horizontalCuts[i]);
            else max_h = max(max_h, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        max_h = max(max_h, h - horizontalCuts[n - 1]);
        int m = verticalCuts.size();
        for(int i = 0; i < m; i++) {
            if(i == 0) max_w = max(max_w, verticalCuts[i]);
            else max_w = max(max_w, verticalCuts[i] - verticalCuts[i - 1]);
        }
        max_w = max(max_w, w - verticalCuts[m - 1]);
        return ((max_h % mod) * (max_w % mod)) % mod;
    }
};