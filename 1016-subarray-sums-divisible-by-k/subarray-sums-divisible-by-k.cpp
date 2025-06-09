class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0, ans=0;
        int n =nums.size();
        mp.insert({0,1});
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find((sum%k < 0? k + sum%k : sum%k))!=mp.end()){
                cout<<i<<" "<<mp[(sum%k < 0? k + sum%k : sum%k)]<<endl;
                ans+=mp[(sum%k < 0? k + sum%k : sum%k)];
            }
            mp[(sum%k < 0? k + sum%k : sum%k)]++;
        }
        return ans;
    }
};