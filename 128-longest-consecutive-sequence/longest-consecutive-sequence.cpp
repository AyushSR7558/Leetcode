class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        int maxi = 1, ConsCount = 1;
        sort(nums.begin(),nums.end());
        for(int i = 1; i < n; i++){
            if((nums[i] == nums[i - 1]) || (nums[i] == (nums[i - 1] + 1))){
                if(nums[i] == nums[i - 1])continue;
                ConsCount++;
                maxi = max(maxi,ConsCount);
            }else{
                ConsCount = 1;
            }
        }
        return maxi;
    }
};