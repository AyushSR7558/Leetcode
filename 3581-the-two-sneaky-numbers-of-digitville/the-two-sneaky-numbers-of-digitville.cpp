class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(marked[nums[i]]) {
                ans.push_back(nums[i]);
            }
            marked[nums[i]] = true;
        }

        return ans;
    }
};