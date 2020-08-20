class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        if(n < 0){
            n = -n;
            x = 1 / x;
        }
        for(int i = 0; i < n; i++)
            result *= (1 / x);
        return result;
    }
};