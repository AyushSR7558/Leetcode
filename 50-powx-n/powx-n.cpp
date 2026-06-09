class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;

        int sign = (n < 0 ? 1: 0);
        if(n < 0) nn *= -1;
        double ans = 1;

        while(nn) {
            if(nn % 2) {
                ans = ans * x;
                nn -= 1;
            }else {
                x = x * x;
                nn /= 2;
            }
        }

        if(sign) return 1 / ans;

        return ans;
    }
};