class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end()); // Sort the array

        for(int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while(i < j) {
                if(nums[i] + nums[j] > nums[k]) {
                    count += j - i; // All pairs (i..j-1) with j and k are valid
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};
