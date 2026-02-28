class Solution {
private:
    string toBinary(int n) {
        string s; 

        while(n) {
            s += (n & 1) + '0';
            n = n >> 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }
public:
    int concatenatedBinary(int n) {
        string s;
        long long mod = 1e9 + 7;

        for(int i = 0; i <= n; i++) {
            s += toBinary(i);
        }

        long long pow = 1;
        long long cnt = 0;
        for(int i =s.size() - 1; i >= 0; i--) {
            if(s[i] == '1') {
                cnt = (cnt + pow) % mod;
            }
            pow = (pow << 1);
            pow = (pow % mod);
        }
        return cnt;
    }
};