class Solution {
public:
    int divide(long long a, long long b) {
        if(a==INT_MIN && b==-1) return INT_MAX;
        int sign = (a<0)^(b<0)? -1:1;
        long long q =0;
        a =abs(a);
        b=abs(b);


        for(int i=31;i>=0;i--){
            if((b<<i )<= a){
                cout<<i;
                a =a- (b<<i);
                q= q + (1<<i);
            }
        }
        return q*sign;
    }
};