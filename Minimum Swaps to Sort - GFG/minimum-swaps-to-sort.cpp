// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums) {
	    int n = nums.size();
	    vector<int> sortedNums = nums;
	    sort(sortedNums.begin(), sortedNums.end());
	    int swaps = 0;
	    for(int i = 0; i < n; i++) {
	        if(nums[i] != sortedNums[i]) {
	            int pos = lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]) - sortedNums.begin();
	            swap(nums[i], nums[pos]);
	            i--;
	            swaps++;
	        } 
	    }

	    return swaps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends