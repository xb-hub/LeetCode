#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        double left = 0, right = x;
        while(right - left > 1e-6)
        {
            double mid = (left + right) / 2;
            if(mid * mid >= x)  right = mid;
            else    left = mid;
        }
        return right;
    }
};