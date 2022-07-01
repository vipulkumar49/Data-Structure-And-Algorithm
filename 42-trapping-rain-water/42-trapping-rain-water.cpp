class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int left_max = 0, right_max = 0;
        int water = 0;
        while(i < j) {
            if(height[i] < height[j]) {
                height[i] >= left_max ? left_max = height[i] : water += (left_max - height[i]);
                i++;
            }
            else {
                height[j] >= right_max ? right_max = height[j] : water += (right_max - height[j] );
                j--;
            }
        }
        return water;
    }
};