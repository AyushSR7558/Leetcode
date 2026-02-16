class Solution {
public:
    int reverseBits(int n) {
        int x = 0;

        for(int i = 0; i < 32; i++) {
            int bit = (n >> i) & 1;   // extract i-th bit (0 or 1)
            x = x | (bit << (31 - i));
        }

        return x;
    }
};
