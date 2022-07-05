class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        int a = 1, b = 1;
        while(b <= k) {
            fib.push_back(b);
            swap(a, b);
            b += a;
        }
        int ans = 0;
        for(int i = fib.size() - 1; i >= 0; i--) {
            if(fib[i] <= k) {
                ans += 1;
                k -= fib[i];
            }
            if(k == 0) break;
        }
        return ans;
    }
};