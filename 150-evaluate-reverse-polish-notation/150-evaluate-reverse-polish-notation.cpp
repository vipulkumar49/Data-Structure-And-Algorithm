class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for(auto const &t : tokens) {
            if(isdigit(t[0])) {
                s.push(stoi(t));
            }
            else if(t[0] == '-' && t.length() >= 2) {
                s.push(stoi(t));
            }
            else {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int c = 0;
                if(t == "+") c = a + b;
                else if(t == "-") c = b - a;
                else if(t == "*") c = a * b;
                else c = b / a;
                s.push(c);
            }
        }
        return s.top();
    }
};