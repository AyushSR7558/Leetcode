class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();

        sort(batteries.begin(), batteries.end(), greater<int>());
        sort(batteries.begin(), batteries.begin() + n);

        long long  extra = accumulate(batteries.begin() + n, batteries.end(), 0L);
        for(int i = 0; i < n - 1; i++) {
            if(extra < ((long long)batteries[i + 1] - batteries[i]) * (i + 1)) {
                return batteries[i] + extra / (i + 1);
            }

            extra -= (long long)(i + 1) * (batteries[i + 1] - batteries[i]);
        }

        return batteries[n - 1] + extra / n;
    }
};