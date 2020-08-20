#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> res;
//         sort(nums.begin(), nums.end());
//         int len = nums.size();
//         if(nums.empty() || nums.front()>0 || nums.back()<0)
//                 return {};
//         for(int i = 0; i < len; i++) {
//             if(nums[i] > 0) break;
//             if(i > 0 && nums[i] == nums[i-1])   continue;
//             int left = i+1;
//             int right = len - 1;
//             while (left < right)
//             {
//                 if(nums[left] + nums[right] == -nums[i]) {
//                     if(left == i + 1 || right == len - 1) {
//                         res.push_back({nums[left], nums[i], nums[right]});
//                         left++;
//                         right--;
//                     }
//                     else if(nums[left] == nums[left - 1])    left++;
//                     else if(nums[right] == nums[right + 1])  right--;
//                     else{
//                         res.push_back({nums[left], nums[i], nums[right]});
//                         left++;
//                         right--;
//                     }
//                     }
//                 else if(nums[left] + nums[right] < -nums[i]) {
//                     left++;
//                 }
//                 else {
//                     right--;
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int left = 0, mid = 1, right = nums.size() - 1;
        for(int i = 0; i < len; i++)
        {
            while(left < right)
            {
                if(nums[left] + nums[right] + nums[mid] == 0)
                {
                    ans.push_back({nums[left], nums[mid], nums[right]});
                }
                else if(nums[left] + nums[right] + nums[mid] > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }
};

int main()
{
}