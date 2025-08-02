class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            int ele = nums[i];
            int secEle = target - ele;
            if(mp.count(secEle)){
                return {mp[secEle],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};