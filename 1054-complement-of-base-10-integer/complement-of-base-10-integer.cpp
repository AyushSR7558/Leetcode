class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int x = 0;
        int indx = 0;
        while(n) {
            if(!(n & 1)) {
                x = x | (1 << indx);
            }
            n >>= 1;
            indx++;
        }
        return x;
    }
};