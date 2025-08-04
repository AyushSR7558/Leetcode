class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        /*
            Here we will require three pointer's 
            * first : first type of fruit
            * second : second type of fruit
            * third : previson consecutive
        */
        int n = fruits.size();
        int fruit1 = -1, fruit2 = -1, prevCons = 0, count = 0, maxi = 0;
        for(int i = 0; i < n; i++){
            if(fruit1 == -1){
                fruit1 = fruits[i];
            }
            if(fruit1 != fruits[i] && fruit2 == -1 ){
                fruit2 = fruits[i];
            }
            if(fruits[i] == fruit1 || fruits[i] == fruit2){
                count++;
            }else{
                fruit1 = fruits[prevCons];
                fruit2 = fruits[i];
                count = i - prevCons + 1;
            }
            maxi = max(count,maxi);
            if(i > 0 && fruits[i - 1] != fruits[i]){
                prevCons = i;
            }
        }
        return maxi;
    }
};