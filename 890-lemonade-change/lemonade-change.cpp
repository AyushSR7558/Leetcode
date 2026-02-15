class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0, b= 0, c = 0;

        int n = bills.size();

        for(int i = 0; i < n; i++) {
            if(bills[i] == 5) {
                a++;
            }else if(bills[i] == 10) {
                if(a == 0) return false;
                a--;
                b++;
            }else {
                if(b > 0 && a > 0) {
                    a--;
                    b--;
                }else if(a >= 3){
                    a -= 3;
                }else {
                    return false;
                }
            }
        }
        return true;
    }
};