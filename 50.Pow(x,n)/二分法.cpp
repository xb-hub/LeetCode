/**
 * 循环
 * 时间复杂度O(log n)
 */
class Solution {
public:
    double myPow(double x, long long n)
    {
        if (n == 0) return 1.0;
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        double result = 1.0;
        double current_x = x;
        while (n) {
            if (n & 1) {
                result = result * current_x;
            }
            current_x = current_x * current_x;
            n >>= 1;  //等价于n /= 2;
        }
        return result;
    }
};

/**
 * 递归
 * 时间复杂度O(log n)
 */
class Solution {
public:
    double myPow(double x, long long n)
    {
        if (n == 0) return 1.0;
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        double mid_x = myPow(x, n / 2);
        if (n & 1) return x * mid_x * mid_x;
        else    return mid_x * mid_x;
    }
};