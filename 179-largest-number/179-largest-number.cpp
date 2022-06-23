class Solution {
public:
    static bool cmp(string a, string b) {
        string ab = a + b;
        string ba = b + a;
        return ab > ba;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            s.push_back(to_string(nums[i]));
        }
        sort(s.begin(), s.end(), cmp);
        string str;
        for(int i = 0; i < n; i++) {
            str += s[i];
        }
        while(str.size() > 1 && str[0] == '0') {
            str = str.substr(1);
        }
        return str;
    }
};