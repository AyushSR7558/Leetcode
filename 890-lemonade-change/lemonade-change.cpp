class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int coinFive = 0, coinTen = 0;
        int n = bills.size();
        for(int i = 0; i < n; i++){
            if(bills[i] == 5){
                coinFive++;
            }else if(bills[i] == 10){
                coinFive--;
                coinTen++;
            }else{
                if(coinTen > 0){
                    coinTen--;
                    coinFive--;
                }else{
                    coinFive -= 3;
                }
            }
            if(coinFive < 0 || coinTen < 0){
                return false;
            }
        }
        return true;
    }
};