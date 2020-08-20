#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> temp;

public:
    void DFS(int step, vector<int> candidates, int target)
    {
        if (target <= 0)
        {
            if (target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        for (int i = step; i < candidates.size() && (target - candidates[i]) >= 0; i++)
        {
            temp.push_back(candidates[i]);
            DFS(i, candidates, target - candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        DFS(0, candidates, target);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 3, 5};
    vector<vector<int>> ans = solution.combinationSum(nums, 8);
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