class Solution {
public:
    bool isPartitionPossible(vector<int> &nums, int &k, vector<int> &subset, int &target, int index) {
        if(index == nums.size()) {
            bool ok = true;
            for(int i = 0; i < k - 1; i++) {
                if(subset[i] != subset[i + 1]) {
                    ok = false;
                    break;
                }
            }
            if(ok) return true;
            else return false;
        }
        for(int i = 0; i < k; i++) {
            if(subset[i] + nums[index] > target) 
                continue;
            int j = i;
            while(--j >= 0) {
                if(subset[j] == subset[i]) break;
            }
            if(j != -1) continue;
            subset[i] += nums[index];
            if(isPartitionPossible(nums, k, subset, target, index + 1)) 
                return true;
            subset[i] -= nums[index];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        if(nums.size() < k) return false;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(sum % k != 0) return false;
        vector<int> subset(k, 0);
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        return isPartitionPossible(nums, k, subset, target, 0);
    }
};