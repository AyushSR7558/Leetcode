class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums,int idx){
        if(idx==nums.size()-1){
            return 0;
        }
        if(idx>=nums.size()){
            return 10000;
        }
        if(dp[idx]!=-1) return dp[idx];
        int minSteps =10000;
        for(int i=1;i<=nums[idx];i++){
            minSteps =  min(1 + helper(nums,idx+i),minSteps) ;
        }
        return dp[idx] =minSteps;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return helper(nums,0);
    }
};