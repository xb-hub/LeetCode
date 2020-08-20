#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int len = nums.size(), ans = 1;
        if(len == 0)    return 0;
        vector<int> dp(len, 1);
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << solution.lengthOfLIS(nums) << endl;
}