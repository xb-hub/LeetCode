/**
 * 12ms
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int i = 0;
    int len = nums.size() - 1;
    // for(i = len - 1; i >= 0; i--) {
    //     if (nums[i] >= nums[i + 1])  continue;
    //     else    break;
    // }
    for(i=nums.size()-1; i && nums[i-1]>=nums[i]; --i);
    if (i) {
        for(j=nums.size()-1; i<j && nums[i-1]>=nums[j]; --j);
			swap(nums[i-1],nums[j]);
        reverse(nums.begin() + (i - 1 == j ? 0 : i), nums.end());
    }
    else {
        sort(nums.begin(), nums.end());
    }
}
};


/**
 * 8ms
 */
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i=0, j=nums.size()-1;
		for(i=nums.size()-1; i && nums[i-1]>=nums[i]; --i);
		if(i){
			for(j=nums.size()-1; i<j && nums[i-1]>=nums[j]; --j);
			swap(nums[i-1],nums[j]);
		}
		reverse(nums.begin()+(i-1==j?0:i),nums.end());
	}
};