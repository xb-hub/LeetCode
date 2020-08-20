class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int current_num = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == current_num) {
                continue;
            }
            current_num = nums[i];
            nums[count] = current_num;
            count ++;
        }
        return count;
    }
};