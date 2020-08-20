#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
private:
    vector<vector<int>> ans;
    // set<vector<int>> result;
    vector<int> temp;

public:
    // void DFS(int step, vector<int> candidates, vector<int> tmp, int target)
    // {
    //     if (step >= candidates.size() || target <= 0)
    //     {
    //         if (target == 0)
    //         {
    //             // ans.push_back(tmp);
    //             result.insert(tmp);
    //         }
    //         return;
    //     }
    //     if(target - candidates[step] >= 0)
    //     {
    //         tmp.push_back(candidates[step]);
    //         DFS(step + 1, candidates, tmp, target - candidates[step]);
    //         tmp.pop_back();
    //     }
    //     DFS(step + 1, candidates, tmp, target);
    // }
    void DFS(int step, vector<int> candidates, int target)
    {
        if (target <= 0)
        {
            if (target == 0)
            {
                // result.insert(temp);
                ans.push_back(temp);
            }
            return;
        }
        for (int i = step; i < candidates.size() && (target - candidates[i]) >= 0; i++)
        {
            if(i > step && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            temp.push_back(candidates[i]);
            DFS(i + 1, candidates, target - candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        DFS(0, candidates, target);
        // DFS(0, candidates, temp, target);
        // for(set<vector<int>>::iterator it = result.begin(); it != result.end(); it++)
        // {
        //     ans.push_back(*it);
        // }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {10,1,2,7,6,1,5};
    vector<vector<int>> ans = solution.combinationSum2(nums, 8);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
}