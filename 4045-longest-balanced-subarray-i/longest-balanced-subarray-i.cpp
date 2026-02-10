class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxi = INT_MIN, n = nums.size();

        for(int i = 0; i < n; i++) {
            int count_even = 0, count_odd = 0;
            unordered_set<int> st;
            for(int j = i; j < n; j++) {
                if(st.count(nums[j])){
                    if(count_odd == count_even) maxi = max(maxi, j - i + 1);
                    continue;
                };

                (nums[j] % 2? count_odd++: count_even++);
                st.insert(nums[j]);
                if(count_odd == count_even) maxi = max(maxi, j - i + 1);
            }
        }
        return (maxi == INT_MIN? 0: maxi);
    }
};