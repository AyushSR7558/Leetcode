class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;

        while(b > 0) {
            if(b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;

        long long ans =
            (power(5, evenPos) * power(4, oddPos)) % MOD;

        return ans;
    }
};