#include <algorithm>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> ans;
        map<vector<int>, bool> exist;
        sort(nums.begin(), nums.end());
        int c, d;
        for(int a = 0; a < size - 3; a++)
        {
            if(nums[a] > target && target > 0)    break;
            for(int b = a + 1; b < size - 2; b++)
            {
                c = b + 1;
                d = size - 1;
                while (c < d)
                {
                    int temp = nums[a] + nums[b] + nums[c] + nums[d];
                    if(temp < target)    c++;
                    else if(temp > target)    d--;
                    else
                    {
                        vector<int> res{nums[a], nums[b], nums[c], nums[d]};
                        if(!exist[res]) ans.push_back(res);
                        exist[res] = true;
                        c++;
                        d--;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> ans;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    ans = solution.fourSum(nums, target);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }
}