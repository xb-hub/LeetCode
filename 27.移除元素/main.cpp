/**
 * 快慢指针
 * 4ms
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

/**
 * algorithm中erase函数
 * 8ms
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]==val) {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};