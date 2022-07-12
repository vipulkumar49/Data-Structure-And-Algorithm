class Solution {
public:
    bool isSquarePossible(vector<int> sides, vector<int> &matchsticks, int index, int &target) {
        if(index == matchsticks.size()) {
            if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]) return true;
            else return false;
        }
        for(int i = 0; i < 4; i++) {
            if(sides[i] + matchsticks[index] > target) 
                continue;
            int j = i;
            while(--j >= 0) {
                if(sides[i] == sides[j]) break;
            }
            if(j != -1) continue;
            sides[i] += matchsticks[index];
            if(isSquarePossible(sides, matchsticks, index + 1, target))
                return true;
            sides[i] -= matchsticks[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) return false;
        vector<int> sides(4, 0);
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int target = sum / 4;
        return isSquarePossible(sides, matchsticks, 0, target);
    }
};