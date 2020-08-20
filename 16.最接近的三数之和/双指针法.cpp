/**
 * 求和的结果存入数组排序后返回结果
 * 16ms
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int sum = 0, result = 0;
        for(int i = 0; i < len - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1])  continue;
            int left = i + 1;
            int right = len - 1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                res.push_back(sum);
                if(sum < target) {
                    left++;
                }
                else if(sum > target) {
                    right--;
                }
                else
                {
                    return target;
                }
            }
        }
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] <<endl;
        }
        if(res.front() > target && res.back() > target)  return res.front();
        else if(res.back() < target && res.front() < target)    return res.back();
        else {
            for(int i = 1; i < res.size(); i++) {
                if(((res[i] - target) * (res[i - 1] - target)) < 0) {
                result = abs(res[i] - target) > abs(res[i - 1] - target) ? res[i - 1] - target : res[i] - target;
                return result + target;
                }
            }
        }
        return 0;
    }
};


/**
 * 求和结果直接进行比较并返回
 * 8ms
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int close_sum = INT_MAX;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int sum = 0, result = 0;
        for(int i = 0; i < len - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1])  continue;
            int left = i + 1;
            int right = len - 1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                int distance = abs(sum - target);
                if(distance < close_sum) {
                    result = sum;
                    close_sum = distance;
                }
                if(sum < target) {
                    left++;
                }
                else if(sum > target) {
                    right--;
                }
                else
                {
                    return target;
                }
            }
        }
        return result;
    }
};
