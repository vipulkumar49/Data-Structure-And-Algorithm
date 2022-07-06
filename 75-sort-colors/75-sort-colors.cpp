class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int red = 0, white = 0, blue = n - 1;
        while(white <= blue) {
            if(nums[white] == 0) {
                swap(nums[red], nums[white]);
                red++, white++;
            }
            else if(nums[white] == 1) {
                white++;
            }
            else {
                swap(nums[white], nums[blue]);
                blue--;
            }
        }
    }
};