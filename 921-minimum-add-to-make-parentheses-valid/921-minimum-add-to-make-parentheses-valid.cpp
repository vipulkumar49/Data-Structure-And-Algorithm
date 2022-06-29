class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        stack<int> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if(!st.empty() && st.top()) {
                    st.pop();
                }
                else {
                    cnt += 1;
                }
            }
        }
        return cnt + st.size();
    }
};