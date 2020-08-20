#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for(auto it : s)
        {
            if(it == '(' || it == '[' || it == '{')
            {
                st.push(it);
            }
            else if(!st.empty() && ((st.top() == '(' && it == ')') || (st.top() == '[' && it == ']') || (st.top() == '{' && it == '}')))
            {
                cout << "pop" << endl;
                st.pop();
            }
            else
            {
                return false;
            }
        }
        if(st.empty())  return true;
        else    return false;
    }
};

int main()
{
    Solution solution;
    string s = "()]]";
    cout << solution.isValid(s) << endl;
}