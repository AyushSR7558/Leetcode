class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 0 0 1 1 1 2 2 3 3 4
        
        int noDup =1, count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                count++;
                nums[noDup++] = nums[i];
            }
        }
        return count+1;
    }
};