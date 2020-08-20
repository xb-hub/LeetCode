#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int area = 0, max_area = 0, min_height;
        while (left < right)
        {
            min_height = min(height[left], height[right]);
            area = (right - left) * min_height;
            max_area = max(area, max_area);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};

int main()
{
    Solution solution;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << solution.maxArea(height) << endl;
}