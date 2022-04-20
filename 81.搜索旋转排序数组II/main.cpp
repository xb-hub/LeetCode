#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right) >> 1;
            if(nums[mid] == target) return true;
            // 如果mid==left==right，left，right移动，直至不相等
            if(nums[mid] == nums[left] && nums[mid] == nums[right])
            {
                left++;
                right--;
            }
            // 左边增
            else if(nums[mid] >= nums[left])
            {
                if(nums[mid] > target && target >= nums[left])   right = mid - 1;
                else    left = mid + 1;
            }
            // 右边增
            else
            {
                if(nums[mid] < target && target <= nums[right])  left = mid + 1;
                else    right = mid - 1;
            }
        }
        return nums[left] == target ? true : false;
    }
};