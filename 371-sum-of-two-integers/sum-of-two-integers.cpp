class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0, carry = 0;
        for(int i = 0; i < 32; i++) {
            if((a & (1 << i)) && (b & (1 << i))) {
                // if Both are one
                if(carry) {
                    sum |= (1 << i);
                    carry = 1;
                }else {
                    carry = 1;
                }
            } else if(a & (1 << i) || (b & (1 << i))) {
                if(carry) {
                    carry = 1;
                }else {
                    sum |= (1 << i);
                }
            }else {
                if(carry) {
                    sum |= (1 << i);
                    carry = 0;
                }

            }
        }
        return sum;
    }
};