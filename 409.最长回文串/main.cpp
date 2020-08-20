#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        if(s.size() == 0)   return 0;
        int ans = 0;
        unordered_map<char, int> count_;
        for(auto it : s)
        {
            count_[it]++;
        }
        for(auto it : count_)
        {
            ans += (it.second / 2 * 2);
            if(it.second % 2 == 1 && ans % 2 == 0)  ans++;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "b";
    cout << solution.longestPalindrome(s) << endl;
}