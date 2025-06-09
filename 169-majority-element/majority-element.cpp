class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int maxi = 0, indx = -1;
        for(auto k : mp){
            if(k.second > maxi){
                indx = k.first;
                maxi = k.second;
            }
        }
        return indx;
    }
};