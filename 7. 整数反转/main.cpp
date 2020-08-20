#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        vector<int> array;
        int ans = 0;
        while(x != 0)
        {
            if(ans > INT_MAX / 10 || ans < INT_MIN / 10)  return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    int x, ans;
    cin >> x;
    ans = solution.reverse(x);
    cout << ans << endl;
}