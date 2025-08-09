class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int count = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                maxi = max(0,maxi);
                count = 1;
                continue;
            }
            count *= nums[i];
            maxi = max(count,maxi);
        }
        count = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] == 0) {
                count = 1;
                continue;
            }
            count *= nums[i];
            maxi = max(count,maxi);
        }
        return maxi;
    }
};