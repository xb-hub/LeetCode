#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        vector<vector<bool>> visit(matrix.size(), vector<bool>(matrix[0].size()));
        vector<vector<int>> ans(matrix);
        for(int i = 0; i < matrix.size; i++)
        {
            for(int j = 0; j < matrix[i].size; j++)
            {
                if(matrix[i][j] == 0)
                {
                    continue;
                }

            }
        }
    }
};

int main()
{
}