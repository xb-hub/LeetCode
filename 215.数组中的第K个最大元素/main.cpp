#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    // 排序
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size() - k];
    // }

    // 堆，优先队列
    // int findKthLargest(vector<int>& nums, int k)
    // {
    //     priority_queue<int, vector<int>, greater<int>> ans;
    //     for(int i = 0; i < nums.size(); i++)
    //     {
    //         ans.push(nums[i]);
    //         if(ans.size() > k)
    //         {
    //             ans.pop();
    //         }
    //     }
    //     return ans.top();
    // }

    //快速选择
    int partition(vector<int>& nums, int left, int right)
    {
        
    }

    int findKthLargest(vector<int>& nums, int k)
    {

    }
};

int main()
{
    vector<int> array = {3,2,1,5,6,4};
    int k;
    cin >> k;
    Solution solution;
    cout << solution.findKthLargest(array, k);
}