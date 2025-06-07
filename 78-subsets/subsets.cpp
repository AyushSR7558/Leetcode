class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> & nums,vector<int> curr, int idx){
       if(idx>=nums.size()){
            ans.push_back(curr);
            return;
       }
       curr.push_back(nums[idx]);
       helper(ans,nums,curr,idx+1);
       curr.pop_back();
       helper(ans,nums,curr,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans,nums,curr,0);
        return ans;
    }
};