class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> row(min(numRows, (int)s.size()));
        int currRow = 0;
        bool isGoingDown = false;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            row[currRow] += s[i];
            if(currRow == 0 || currRow == numRows - 1) isGoingDown = !isGoingDown;
            currRow += isGoingDown ? 1 : -1;
        }
        string res;
        for(auto i: row) {
            res += i;
        }
        return res;
    }
};