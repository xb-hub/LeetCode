#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.size() == 0)    return "";
        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            int len = min(ans.size(), strs[i].size()), index = 0;
            for(int j = 0; j < len; j++)
            {
                if(ans[j] != strs[i][j])
                {
                    break;
                }
                index = j + 1;
            }
            ans = ans.substr(0, index);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<string> strs = {"flower","flow","flight"};
    cout << solution.longestCommonPrefix(strs) << endl;
}