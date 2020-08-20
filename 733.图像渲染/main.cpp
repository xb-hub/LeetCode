#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
public:
    void dfs(vector<vector<int>>& image, int x, int y, int newColor, int curColor)
    {
        if(image[x][y] == curColor)
        {
            image[x][y] = newColor;
            for(int i = 0; i < 4; i++)
            {
                int new_x = x + dx[i], new_y = y + dy[i];
                if(new_x >= 0 && new_y >= 0 && new_x < image.size() && new_y < image[0].size())
                {
                    dfs(image, new_x, new_y, newColor, curColor);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int curColor = image[sr][sc];
        if(curColor != newColor)
        {
            dfs(image, sr, sc, newColor, curColor);
        }
        return image;
    }
};

int main()
{
    vector<vector<int>> image = {{1, 1, 1},{1, 1, 0},{1, 0, 1}};
    Solution solution;
    solution.floodFill(image, 1, 1, 2);
    for(int i = 0; i < image.size(); i++)
    {
        for(int j = 0; j < image[0].size(); j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}