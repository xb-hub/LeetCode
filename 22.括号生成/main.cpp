#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string s = "";
        if(n == 0)  return ans;
        dfs(0, n, s, ans, 0, 0);
        return ans;
    }

    bool valid(const string& str) {
        int balance = 0;
        for (char c : str)
            if (c == '(')
                ++balance;
            else {
                --balance;
                if (balance < 0)
                    return false;
            }
        return balance == 0;
    }

    void dfs(int level, int n, string s, vector<string> &ans, int left, int right)
    {
        // cout << s << endl;
        if(level == 2 * n)
        {
            if(valid(s))    ans.push_back(s);
            return;
        }
        if(left < n)
        {
            dfs(level + 1, n, s + "(", ans, left + 1, right);
        }
        if(right < n)
        {
            dfs(level + 1, n, s + ")", ans, left, right + 1);
        }
    }
};

int main()
{
    Solution solution;
    vector<string> ans = solution.generateParenthesis(5);
    cout << ans.size() << endl;
    for(auto it : ans)
    {
        cout << it << endl;
    }
}