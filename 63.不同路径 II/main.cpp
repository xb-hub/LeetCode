#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        long long dp[1000][1000];
        int width = obstacleGrid[0].size(), height = obstacleGrid.size();
        // cout << obstacleGrid.size() << " " << obstacleGrid[0].size() << endl;
        for(int i = 0; i < width; i++)
        {
            if(obstacleGrid[i][0] == 1) break;
            else
            {
                dp[i][0] = 1;
            }
        }
        for(int j = 0; j < height; j++)
        {
            if(obstacleGrid[0][j] == 1) break;
            else
            {
                dp[0][j] = 1;
            }  
        }
        for(int i = 1; i < height; i++)
        {
            for(int j = 1; j < width; j++)
            {
                if(obstacleGrid[i][j] == 1) continue;
                else    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // for(int i = 0; i < height; i++)
        // {
        //     for(int j = 0; j < width; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[height - 1][width - 1];
    }
};

int main()
{
    vector<vector<int> > road(3, vector<int>(3));
    road[0][0] = 0; road[0][1] = 0; road[0][2] = 0;
    road[1][0] = 0; road[1][1] = 1; road[1][2] = 0;
    road[2][0] = 0; road[2][1] = 0; road[2][2] = 0;
    Solution soultion;
    cout << soultion.uniquePathsWithObstacles(road);
}