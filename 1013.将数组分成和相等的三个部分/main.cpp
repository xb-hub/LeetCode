#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
   public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0, count = 0, tmp = 0;
        // for (auto it : A) {
        //     sum += it;
        // }
        sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0) return false;
        sum /= 3;
        for(int i = 0; i < A.size(); i++)
        {
            tmp += A[i];
            if(tmp == sum)
            {
                count++;
                tmp = 0;
            }
        }
        if(count >= 3)  return true;    // sum==0时可能大于3
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> A = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    cout << solution.canThreePartsEqualSum(A) << endl;
}