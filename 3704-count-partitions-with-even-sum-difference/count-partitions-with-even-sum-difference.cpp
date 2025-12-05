class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        
        int totSum = accumulate(nums.begin(), nums.end(),0), currSum = 0, count = 0;
        cout << totSum << endl;

        for(int i = 0; i < n - 1; i++) {
            currSum += nums[i];
            if(!((totSum - 2 * currSum) & 1) )count++;
        }
        return count;
    }
};