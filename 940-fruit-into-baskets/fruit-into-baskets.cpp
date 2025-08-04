class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        map<int,int> basket;
        int left = 0, right = 0, maxi = 0;
        while(right < n){
            basket[fruits[right]]++;
            
            while(basket.size() > 2){
                basket[fruits[left]]--;

                if(basket[fruits[left]] == 0){
                    basket.erase(fruits[left]);
                }

                left++;
            }
            maxi = max(maxi, right- left + 1);
            right++;
        }
        return maxi;
    }
};