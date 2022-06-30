class Solution {
public:
    int longestOnes(vector<int>& nums, int &k) {
        int ws = 0, we = 0;
        int len = 0, cnt = 0;
        int n = nums.size();
        while(we < n) {
            if(nums[we] == 0) cnt++;
            we++;
            while(cnt > k) {
                if(nums[ws] == 0) cnt--;
                ws++;
            }
            if(we - ws > len) len = we - ws; 
        }
        return len;
    }
};