#include <iostream>
#include <vector>
using namespace std;

// class Solution
// {
// public:
//     int strStr(string haystack, string needle)
//     {
//         if(needle.size() == 0)  return 0;
//         else if(haystack.size() == 0)   return -1;
//         if(haystack.size() < needle.size()) return -1;
//         if(haystack.size() == needle.size() && haystack == needle)  return 0;
//         int size = needle.size();
//         for(int i = 0; i <= haystack.size() - size; i++)
//         {
//             if(haystack.substr(i, size) == needle)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int h_size = haystack.size(), n_size = needle.size();
        if(n_size == 0)  return 0;
        else if(h_size == 0)   return -1;
        if(h_size < n_size) return -1;
        if(h_size == n_size && haystack == needle)  return 0;
        vector<int> nextval(n_size + 1);
        GetNextval(needle, nextval);
        int h_index = 0, n_index = 0;
        while (h_index < h_size && n_index < n_size)
        {
            if (n_index == -1 || haystack[h_index] == needle[n_index])
            {
                h_index++;
                n_index++;
            }
            else
            {
                n_index = nextval[n_index];
            }
        }
        if (n_index == n_size)
            return h_index - n_index;
        else
            return -1;
    }

    void GetNextval(string needle, vector<int> &nextval)
    {
        int j = -1, i = 0;//j在后面，i在前面
        nextval[i] = j;
        while(i < needle.size())
        {
            while(j >= 0 && needle[i] != needle[j]) j = nextval[j];
            i++, j++;
            nextval[i] = j;
        }   
    }
};

int main()
{
    Solution solution;
    int ans = solution.strStr("hello", "ll");
    cout << ans << endl;
}