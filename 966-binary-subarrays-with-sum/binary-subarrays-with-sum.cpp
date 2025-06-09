class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int>presum;
        unordered_map<int,int>mp;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            presum.push_back(sum);
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(presum[i] - goal) || presum[i] == goal){
                if(presum[i] == goal)ans += 1;
                ans += mp[presum[i] - goal];
            }else{
                ans += 0;
            }
            mp[presum[i]]++;
        }
        return ans;
    }
};