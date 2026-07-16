class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        vector<int> prefixGcd(n);

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;

        int i = 0, j = n - 1;
        while(i < j) {
            sum += gcd(prefixGcd[i], prefixGcd[j]);
            i++; j--;
        }
        return sum;
    }
};