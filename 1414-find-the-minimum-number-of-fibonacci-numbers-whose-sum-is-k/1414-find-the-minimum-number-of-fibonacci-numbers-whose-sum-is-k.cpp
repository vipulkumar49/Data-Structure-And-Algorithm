class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if(k == 0) return 0;
        int a = 1, b = 1;
        while(b <= k) {
            swap(a, b);
            b += a;
        }
        return 1 + findMinFibonacciNumbers(k - a);
    }
};