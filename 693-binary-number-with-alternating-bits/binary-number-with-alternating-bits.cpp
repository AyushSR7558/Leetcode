class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long x = n, y = n >> 1;
        long long temp = x ^ y;
        return !(temp & (temp + 1));
    }
};