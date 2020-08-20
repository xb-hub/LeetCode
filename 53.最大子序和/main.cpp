#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = nums[0], temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            temp = temp + nums[i];
            if (temp > max_sum)
            {
                max_sum = temp;
            }
            if (temp < 0)
            {
                temp = 0;
            }
        }
        return max_sum;
    }
};

int main()
{
    Solution solution;
    // vector<int> array = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> array = {-2, -1};
    cout << solution.maxSubArray(array);
}