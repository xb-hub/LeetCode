#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<bool> > dp(len,vector<bool>(len));
        int max_len = 1, left = 0;
        for(int i = 0; i < s.size(); i++)
        {
            dp[i][i] = true;
            if(i < s.size() - 1 && s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                max_len = 2;
                left = i;
            }
        }
        for(int i = 1; i < s.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(i - j >= 2 && s[i] == s[j])
                {
                    dp[j][i] = dp[j + 1][i - 1];
                    if((i - j + 1 > max_len) && dp[j][i])
                    {
                        max_len = i - j + 1;
                        left = j;
                    }
                }
            }
        }
        return s.substr(left, max_len);
    }
};

int main()
{
    string s = "cbbd";
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
}