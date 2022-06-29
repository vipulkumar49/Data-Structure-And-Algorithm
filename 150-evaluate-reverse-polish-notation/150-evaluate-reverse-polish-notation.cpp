class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for(int i = 0; i < n; i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
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
            else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};