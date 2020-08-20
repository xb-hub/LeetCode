#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp[10000];
        dp[1] = 1;  dp[2] = 2;
        for(int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main()
{
    Solution solution;
    cout << solution.climbStairs(3) << endl;
}