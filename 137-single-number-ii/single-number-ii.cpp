class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        for(auto ele:mp){
            int val =ele.first;
            int cnt = ele.second;
            if(cnt==1) return val;
        }
        return -1;

    }
};