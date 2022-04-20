#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size();
        while(left < right)
        {
            int mid = (left + right) >> 1;
            if(nums[mid] >= nums[0] && nums[0] > nums.back())   left = mid + 1;
            else    right = mid;
        }
        return nums[left];
    }
};