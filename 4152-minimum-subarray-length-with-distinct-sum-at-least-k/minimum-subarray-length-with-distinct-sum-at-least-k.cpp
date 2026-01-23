class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> freq;
        int maxi = n + 1;

        while(r < n) {
            if(!freq.count(nums[r])) {
                sum += nums[r];
            }
            freq[nums[r]]++;

            if(sum >= k) maxi = min(r - l + 1, maxi);

            while(sum >= k) {
                freq[nums[l]]--;
                maxi = min(r - l + 1, maxi);
                if(freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                if(!freq.count(nums[l])) sum -= nums[l];
                l++;
            }
            r++;
        }
        return (maxi == n + 1? -1: maxi);
        
    }
};