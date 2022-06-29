class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for(int i = 0; i < n; i++) {
            if(isdigit(tokens[i][0])) {
                s.push(stoi(tokens[i]));
            }
            else if(tokens[i][0] == '-' && tokens[i].length() >= 2) {
                s.push(stoi(tokens[i]));
            }
            else {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int c = 0;
                if(tokens[i] == "+") c = a + b;
                else if(tokens[i] == "-") c = b - a;
                else if(tokens[i] == "*") c = a * b;
                else c = b / a;
                s.push(c);
            }
        }
        return s.top();
    }
};