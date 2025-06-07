class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n =nums.size();
        vector<int> v(n+1,0);
        vector<int> ans(2,0);
        for(int i=0;i<n;i++){
            v[nums[i]] +=1;
        }
        for(int i=1;i<n+1;i++){
            if(v[i]==0){
                ans[1] = i;
            }
            if(v[i]==2){
                ans[0] = i;
            }
        }
        return ans;
    }
};