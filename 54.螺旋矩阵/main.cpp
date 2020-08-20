#include <iostream>
#include <vector>
using namespace std;

class Solution
{    
private:
    int dx[4] = {0, 1, 0, -1};   int dy[4] = {1, 0, -1, 0};
    vector<vector<bool>> st;
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if(matrix.size() == 0)  return ans;
        int x = 0, y = 0, d = 0;
        int m = matrix.size(), n = matrix[0].size();
        st.resize(m, vector<bool>(n, false));
        for(int i = 0; i < n * m; i++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || st[nx][ny])
            {
                d = (d + 1) % 4;
                nx = x + dx[d];    ny = y + dy[d];
            }
            st[x][y] = true;
            ans.push_back(matrix[x][y]);
            x = nx; y = ny;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> ans;
    vector<vector<int>> matirx = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    ans = solution.spiralOrder(matirx);
    for(auto it : ans)
    {
        cout << it << " ";
    }
}