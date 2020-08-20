#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string ans = "";
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i = i; i < 13 && num != 0; i++)
        {
            while (num >= value[i])
            {
                ans += roman[i];
                num -= value[i];
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string ans;
    ans = solution.intToRoman(4);
    cout << ans << endl;
}