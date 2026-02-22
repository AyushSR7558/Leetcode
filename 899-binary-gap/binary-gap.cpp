class Solution {
public:
    int binaryGap(int n) {
        int maxi = 0, cnt = 1;

        if(n == 0 || !(n & (n -1))) {
            return 0;
        }

        while(n && !(n & 1)) {
            n = n >> 1;
        }

        while(n) {
            if(n & 1) {
                maxi = max(cnt, maxi);
                cnt = 1;
            }else {
                cnt++;
            }
            n = n >> 1;
        }
        
       return maxi; 
    }
};