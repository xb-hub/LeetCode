#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0;
        map<char, int> roman;
        roman.insert(map<char,int>::value_type('I',1));
        roman.insert(map<char,int>::value_type('V',5));
        roman.insert(map<char,int>::value_type('X',10));
        roman.insert(map<char,int>::value_type('L',50));
        roman.insert(map<char,int>::value_type('C',100));
        roman.insert(map<char,int>::value_type('D',500));
        roman.insert(map<char,int>::value_type('M',1000));
        for(int i = 0; i < s.size(); i++)
        {
            if(roman[s[i]] < roman[s[i + 1]])
            {
                ans += roman[s[i + 1]] - roman[s[i]];
                i++;
            }
            else
            {
                ans += roman[s[i]];
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string input = "IV";
    cout << solution.romanToInt(input) << endl;
}