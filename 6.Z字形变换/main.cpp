#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)    return s;
        vector<char> ans[numRows];
        string result = "";
        bool flag = true;  // false向下走，true向上走
        int row = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(row == 0 || row == numRows - 1)
            {
                flag = !flag;
            }
            ans[row].push_back(s[i]);
            if(flag)    row--;
            else    row++;
        }
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < ans[i].size(); j++)
            {
                result += ans[i][j];
            }
        }
        return result;
    }
};

int main()
{
    string s;
    int numRows;
    cin >> s >> numRows;
    Solution soultion;
    cout << soultion.convert(s, numRows) << endl;
}