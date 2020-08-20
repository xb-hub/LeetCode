#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<int>> box(9, vector<int>(9, 0));
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '1';
                    if(++row[i][num] == 2 || ++col[j][num] == 2 || ++box[i / 3 * 3 + j / 3][num] == 2)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{

}