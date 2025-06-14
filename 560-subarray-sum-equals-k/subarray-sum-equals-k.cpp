class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n =nums.size();
        mp.insert({0,1});
        int sum =0,ans=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(mp.find(sum-k) != mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;

    }
};