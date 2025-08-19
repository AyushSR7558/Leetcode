class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        long long zeroStrike = 0;
        for(int x: nums) {
            if(x == 0) {
                zeroStrike++;
                result += zeroStrike;
            }else {
                zeroStrike = 0;
            }
        }
        return result;
    }
};