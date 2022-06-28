class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0, n = arr.size();
        unordered_map<int, int> ump;
        for(int i = 0; i < n; i++) {
            if(ump.find(arr[i] - difference) != ump.end()) 
                ump[arr[i]] = 1 + ump[arr[i] - difference];
            else ump[arr[i]] = 1;
            res = max(ump[arr[i]], res);
        }
        return res;
    }
};