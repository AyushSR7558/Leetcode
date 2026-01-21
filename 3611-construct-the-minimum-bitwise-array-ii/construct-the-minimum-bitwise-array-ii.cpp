class Solution {
private:
    int getVal(int n) {
        int indx = 0;
        while(n) {
            if(n & 1) {
                indx++;
            }else {
                break;
            }
            n = n >> 1;
        }
        return indx - 1;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & 1)
                ans.push_back( (nums[i] ^ (1 << getVal(nums[i]))));
            else 
                ans.push_back(-1);
        }
        return ans;
    }
};