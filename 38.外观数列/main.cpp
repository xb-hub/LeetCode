#include <iostream>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if(n == 1)  return "1";
        string num = "1", ans;
        for(int i = 0; i < n - 1; i++)
        {
            int left = 0, right = 0;
            ans = "";
            while (right < num.size())
            {
                while (num[left] == num[right] && right < num.size())
                {
                    right++;
                }
                ans += (to_string(right - left) + num[left]);
                left = right;
            }
            num = ans;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.countAndSay(4) << endl;
}