#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                int count = 0;
                queue<int> queue_i, queue_j;
                queue_i.push(i);    queue_j.push(j);
                while(!queue_i.empty())
                {
                    int curr_i = queue_i.front(), curr_j = queue_j.front();
                    queue_i.pop();  queue_j.pop();
                    if(curr_i < 0 || curr_j < 0 || curr_i >= grid.size() || curr_j >= grid[0].size() || grid[curr_i][curr_j] != 1)
                    {
                        continue;
                    }
                    grid[curr_i][curr_j] = 0;
                    count++;
                    queue_i.push(curr_i - 1); queue_i.push(curr_i); queue_i.push(curr_i);  queue_i.push(curr_i + 1);
                    queue_j.push(curr_j); queue_j.push(curr_j - 1); queue_j.push(curr_j + 1);  queue_j.push(curr_j);
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << solution.maxAreaOfIsland(grid) << endl;
}