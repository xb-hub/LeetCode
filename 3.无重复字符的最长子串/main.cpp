#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)   return 0;
        int max_len = 0, len = 0;
        int start = 0, end = 0;
        vector<int> index(256, -1);
        while(end < s.size())
        {
            if(index[s[end]] >= start)
            {
                start = index[s[end]] + 1;
                len = end - start;
            }
            index[s[end]] = end;
            end++;
            len++;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};

int main()
{
    Solution solution;
    string s;
    cin>>noskipws;//设置cin读取空白符；
    cin >> s;
    int length = solution.lengthOfLongestSubstring(s);
    cout << length;
}