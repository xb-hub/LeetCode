#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<vector<bool>> st;
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix;
        if(n == 0)  return matrix;
        matrix.resize(n, vector<int>(n));
        st.resize(n, vector<bool>(n));
        int x = 0, y = 0, d = 0;
        for(int i = 1; i <= n * n; i++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || st[nx][ny])
            {
                d = (d + 1) % 4;
                nx = x + dx[d]; ny = y + dy[d];
            }
            st[x][y] = true;
            matrix[x][y] = i;
            x = nx; y = ny;
        }
        return matrix;
    }
};

int main()
{
    Solution solution;
    int n = 3;
    vector<vector<int>> matrix;
    matrix = solution.generateMatrix(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}