#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        vector<int> index = {-1, -1};
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                int i = mid;
                while(i >= 0 && nums[i] == target)
                {
                    i--;
                }
                index[0] = i + 1;
                i = mid;
                while(i < nums.size() && nums[i] == target)
                {
                    i++;
                }
                index[1] = i - 1;
                break;
            }
        }
        return index;
    }
};

int main()
{
    Solution solution;
    vector<int> index, nums = {1};
    index = solution.searchRange(nums, 1);
    cout << "[" << index[0] << " ," << index[1] << "]" << endl;
}