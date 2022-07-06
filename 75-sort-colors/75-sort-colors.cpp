class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) 
                cnt1++;
            else if(nums[i] == 1) 
                cnt2++;
            else 
                cnt3++;
        }
        for(int i = 0; i < n; i++) {
            if(i < cnt1) nums[i] = 0;
            else if(i < cnt1 + cnt2) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};