class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_ending_here = 0, max_so_far = INT_MIN;
        for(int i = 0; i < n; i++) {
            max_ending_here = max(nums[i], max_ending_here + nums[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
};