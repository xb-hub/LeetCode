#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right) >> 1;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[left])
            {
                if(nums[mid] > target && target >= nums[left])   right = mid - 1;
                else    left = mid + 1;
            }
            else
            {
                if(nums[mid] < target && target <= nums[right]) left = mid + 1;
                else    right = mid - 1;
            }
        }
        return target == nums[left] ? left : -1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << solution.search(nums, 0) << endl;
}