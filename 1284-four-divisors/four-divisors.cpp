class Solution {
private:
    int helper(int n) {
        vector<int> divisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n / i)
                    divisors.push_back(n / i);
            }

            if(divisors.size() > 4) return 0;
        }

        if(divisors.size() == 4) return accumulate(divisors.begin(), divisors.end(), 0);
        return 0;
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size(), sum = 0;

        for(int i = 0; i < n; i++) {
            sum += helper(nums[i]);
        }
        return sum;
    }
};