class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) pos.push_back(nums[i]);
            if(nums[i] < 0) neg.push_back(nums[i]);
        }
        int negIndx = 0, posIndx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i & 1){
                nums[i] = neg[negIndx++];
            }else{
                nums[i] = pos[posIndx++];
            }
        }
        return nums;
    }
};