class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_ending_here = nums[0], min_ending_here = nums[0];
        int max_so_far = nums[0];
        for(int i = 1; i < n; i++) {
            int tmp = max({nums[i], max_ending_here* nums[i], min_ending_here * nums[i]});
            min_ending_here = min({nums[i], max_ending_here * nums[i], min_ending_here * nums[i]});
            max_ending_here = tmp;
            max_so_far = max(max_ending_here, max_so_far);
        }
        return max_so_far;
    }
};