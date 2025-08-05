class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), m = baskets.size();
        int count = 0;
        vector<bool> placed(m,false);
        for(int i = 0; i < n; i++){
            int indx = -1;
            for(int j = 0; j < m; j++){
                if(baskets[j] >= fruits[i] && !placed[j]){
                    indx = j; 
                    break;
                }
            }
            if(indx != -1){
                placed[indx] = true;
            }else{
                count++;
            }
        }
        return count;
    }
};