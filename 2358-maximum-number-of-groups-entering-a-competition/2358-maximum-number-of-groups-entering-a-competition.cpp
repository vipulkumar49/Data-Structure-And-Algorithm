class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int size = grades.size();
        int groups = 0;
        int i = 0;
        while(i < size) {
            if(i += groups < size) {
                groups += 1;
                i += groups;
            }
            else {
                break;
            }
        }
        return groups;
    }
};