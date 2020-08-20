#include <iostream>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if(divisor == 0 || dividend == 0)    return 0;
        bool flag = false;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        {
            flag = true;
        }
        long long a = abs(dividend), tmp_d = abs(divisor);
        long long ans = 0;
        while (a >= tmp_d)
        {
            long long tmp = 1, b = abs(divisor);
            while ((b << 1) < a)
            {
                b = b << 1;
                tmp = tmp << 1;
            }
            a = a - b;
            ans += tmp;
        }
        if(flag)    ans = -ans;
        if(ans > INT_MAX)   ans = INT_MAX;
        else if(ans < INT_MIN)  ans = INT_MIN;
        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.divide(-1, 1) << endl;
}