#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid = 0;
        bool flag = false;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        if (target > nums[mid])
        {
            return mid + 1;
        }
        else
        {
            return mid;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    cout << solution.searchInsert(nums, 0) << endl;
}