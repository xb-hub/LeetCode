#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int dp[grid.size()][grid[0].size()];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < grid.size(); i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int j = 1; j < grid[0].size(); j++)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for(int i = 1; i < grid.size(); i++)
        {
            for(int j = 1; j < grid[0].size(); j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        // for(int i = 0; i < grid.size(); i++)
        // {
        //     for(int j = 0; j < grid[0].size(); j++)
        //     {
        //         cout << dp[i][j] << "     ";
        //     }
        //     cout << endl;
        // }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > grid(3, vector<int>(3));
    grid[0][0] = 1; grid[0][1] = 3; grid[0][2] = 1;
    grid[1][0] = 1; grid[1][1] = 5; grid[1][2] = 1;
    grid[2][0] = 2; grid[2][1] = 2; grid[2][2] = 1;
    cout << solution.minPathSum(grid) << endl;
}