class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int l = 0, r = 0, n = prices.size();

        long long count = 0;

        while(r < n) {
            while(!(l == r || prices[l] - prices[r] == (r - l))) l++;
            count += r - l + 1;
            r++;
        }

        return count;

    }
};