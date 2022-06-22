class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int best = INT_MIN, curr = 0;
        for(int i = 0; i < n; i++) {
            curr = max(curr + nums[i], nums[i]);
            best = max(best, curr);
        }
        return best;
    }
};