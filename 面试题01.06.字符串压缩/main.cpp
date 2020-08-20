#include <iostream>
using namespace std;

class Solution
{
public:
    string compressString(string S)
    {
        string ans;
        int right = 0;
        for(int i = 0; i < S.size(); i++)
        {
            while(S[i] == S[right] && right < S.size())
            {
                right++;
            }
            ans += S[i] + to_string(right - i);
            i = right - 1;
        }
        return ans.size() < S.size() ? ans : S;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution solution;
    cout << solution.compressString(s) << endl;
}