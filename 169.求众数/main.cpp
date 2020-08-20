#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    //哈希表
    // int majorityElement(vector<int> &nums)
    // {
    //     map<int, int> ans;
    //     int majority;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         ans[nums[i]]++;
    //         if (ans[nums[i]] > nums.size() / 2)
    //         {
    //             return nums[i];
    //         }
    //     }
    //     // for(map<int, int>::iterator it = ans.begin(); it != ans.end(); it++)
    //     // {
    //     //     if(it->second > nums.size() / 2)
    //     //     {
    //     //         majority = it->first;
    //     //         break;
    //     //     }
    //     // }
    //     // return majority;
    // }

    //排序
    // int majorityElement(vector<int> &nums)
    // {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size() / 2];
    // }

    //Boyer-Moore 投票算法
    int majorityElement(vector<int> &nums)
    {
        int candidate, count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(count == 0)
            {
                candidate = nums[i];
                count++;
            }
            else
            {
                if(nums[i] == candidate)    count++;
                else    count--;
            }
        }
        return candidate;
    }

    //分治
    // int majorityElement(vector<int> &nums)
    // {
        
    // }
};

int main()
{
    Solution solution;
    vector<int> array = {3, 2, 3};
    cout << solution.majorityElement(array);
}