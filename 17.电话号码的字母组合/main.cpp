#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<char, string> key = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                         {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

class Solution
{
private:
    
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if(digits.size() == 0)  return ans;
        string str = "";
        dfs(digits, 0, str, ans);
        return ans;
    }

    void dfs(string digit, int level, string str, vector<string> &ans)
    {
        if(level == digit.size())
        {
            ans.push_back(str);
            return;
        }
        for(int i = 0; i < key[digit[level]].size(); i++)
        {
            dfs(digit, level + 1, str + key[digit[level]][i], ans);
        }
    }
};

int main()
{
    Solution solution;
    vector<string> ans = solution.letterCombinations("23");
    for(auto it : ans)
    {
        cout << it << endl;
    }
}