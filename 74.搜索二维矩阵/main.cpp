#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if(m == 1 && n == 1)    return matrix[0][0] == target;
        int up = 0, down = m - 1;
        while(up < down)
        {
            int mid = (up + down) >> 1;
            if(target < matrix[mid][n - 1])    down = mid;
            else if(target > matrix[mid][n - 1])    up = mid + 1;
            else return true;
        }
        int left = 0, right = n - 1;
        while(left <= right)
        {
            int mid = (left + right) >> 1;
            // if(matrix[up][mid] >= target)    right = mid;
            // else   left = mid + 1;
            if(matrix[up][mid] > target)    right = mid - 1;
            else if(matrix[up][mid] < target)   left = mid + 1;
            else return true;
        }
        // return matrix[up][left] == target; 
        return false;
    }
};