class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0, n=nums.size();
        if(n==1) return false;
        mp.insert({0,-1});
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find((sum%k))!=mp.end() && (i-mp[sum%k]) >= 2){
                cout<<sum<<" "<<k;
                return  true;
            }
            mp.insert({sum%k,i});
        }
        return false;
    }
};