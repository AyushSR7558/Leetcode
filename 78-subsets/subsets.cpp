class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> result;
        int n =nums.size();
        for(int i=0;i<(1<<n);i++){
            int j =i, count=0;
            vector<int> ans;
            while(j!=0){
                if(j&1) ans.push_back(nums[count]);
                count++;
                j>>=1;
            }
            result.push_back(ans);
        }
        return result;
    }
};