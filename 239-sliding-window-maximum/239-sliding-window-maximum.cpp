class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<int> res;
        int n = nums.size();
        int ws = 0, we = 0;
        while(we < n) {
            window.insert(nums[we]);
            we++;
            if(we - ws == k) {
                auto it = window.end();
                it--;
                int mx = *it;
                res.push_back(mx);
                if(window.find(nums[ws]) != window.end())
                    window.erase(window.find(nums[ws]));
                ws++;
            }
        }
        return res;
    }
};