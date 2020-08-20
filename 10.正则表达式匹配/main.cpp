#include <iostream>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int index = 0;
        while(s[index] == p[index])
        {
            index++;
        }
        if(index == s.size())   return true;
    }
};

int main()
{
    Solution solution;
}