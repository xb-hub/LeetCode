#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int len = str.size(), i = 0;
        if(len == 0)    return 0;
        long long ans = 0;
        int flag = 1;
        while(str[i] == ' ')
        {
            i++;
            cout << str[i] << endl;
        }
        if((i == len) || (str[i] != '+' && str[i] != '-' && !isdigit(str[i])))    return 0;
        if(isdigit(str[i])) ans = str[i] - '0';
        else    flag = str[i] == '-' ? -1 : 1;
        i++;
        while(isdigit(str[i]))
        {
            ans = ans * 10 + str[i] - '0';
            if(flag * ans > INT_MAX)    return INT_MAX;
            if(flag * ans < INT_MIN)    return INT_MIN;
            i++;
        }
        ans *= flag;
        return ans;
    }
};

int main()
{
    Solution solution;
    string s;
    cin >> s;
    cout << solution.myAtoi(s) << endl;
}