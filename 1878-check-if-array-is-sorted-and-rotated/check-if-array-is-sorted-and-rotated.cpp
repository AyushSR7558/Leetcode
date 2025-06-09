class Solution {
public:
    bool check(vector<int>& nums) {
        // 3 4 5 1 2 
        int n =nums.size();
        int error =0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) error++;
            if(error==1 && nums[0]<nums[n-1]) error++;
        }
    
        return error<=1;
    }
};