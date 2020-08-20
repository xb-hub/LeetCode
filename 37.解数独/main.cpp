#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<bool>> box;
    vector<vector<bool>> row;
    vector<vector<bool>> col;
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        box.resize(board.size() + 1, vector<bool>(board.size() + 1));
        row.resize(board.size() + 1, vector<bool>(board.size() + 1));
        col.resize(board.size() + 1, vector<bool>(board.size() + 1));
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board.size(); j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    row[i][num] = true;
                    col[j][num] = true;
                    box[i / 3 * 3 + j / 3][num] = true;
                }
            }
        }

        dfs(board, 0);
    }

    bool dfs(vector<vector<char>> &board, int level)
    {
        int x = level / 9, y = level % 9;
        if(level == 81) return true;
        if(board[x][y] != '.')
        {
            return dfs(board, level + 1);
        }
        for(int i = 1; i <= 9; i++)
        {
            if(!getStatus(x, y, i))
            {
                board[x][y] = char(i + 48);
                row[x][i] = true;
                col[y][i] = true;
                box[x / 3 * 3 + y / 3][i] = true;
                if(dfs(board, level + 1))
                {
                    return true;
                }
                board[x][y] = '.';
                row[x][i] = false;
                col[y][i] = false;
                box[x / 3 * 3 + y / 3][i] = false;
            }
        }
        return false;
    }
    
    bool getStatus(int x, int y, int num)
    {
        return (row[x][num] || col[y][num] || box[x / 3 * 3 + y / 3][num]);
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    solution.solveSudoku(board);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}