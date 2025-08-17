class Solution {
public:
    const int MOD = 1e9+7;
    int xorAfterQueries(vector<int>& k, vector<vector<int>>& q) {
        int n = k.size(), m = q.size();
        vector<long long> nums(n,0);
        for(int i = 0; i < n; i++) {
            nums[i] = k[i];
        }
        for(int i = 0; i < m; i++) {
            int l = q[i][0], r = q[i][1], k = q[i][2], v = q[i][3];
            for(int j = l; j <= r; j += k) {
                nums[j] = (nums[j] * v * 1LL) % MOD;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};