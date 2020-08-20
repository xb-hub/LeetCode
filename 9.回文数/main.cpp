#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        string r_num = num;
        reverse(r_num.begin(), r_num.end());
        if(num == r_num)    return true;
        return false;
    }
};

int main()
{
    Solution solution;
    int x;
    cin >> x;
    cout << solution.isPalindrome(x) << endl;
}