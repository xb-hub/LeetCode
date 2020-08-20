#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int size = nums.size();
        int left = 0, right = size - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[0] > nums[mid])
            {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid;
            }
            else
            {
                if (target <= nums[mid] && target >= nums[left])
                    right = mid;
                else
                    left = mid + 1;
            }
        }
        return left == right && target == nums[left] ? left : -1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << solution.search(nums, 0) << endl;
}