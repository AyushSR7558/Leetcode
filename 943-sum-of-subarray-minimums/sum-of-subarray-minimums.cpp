class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        long long mod = 1e9 + 7;
        vector<int> vecNSE(n), vecPSE(n);
    
        stack<int> nse, pse;

        for(int i = 0; i < n; i++) {
            int curr = nums[i];

            while(!pse.empty() && nums[pse.top()] >= curr) {
                pse.pop();
            }
            vecPSE[i] = (pse.empty()? -1: pse.top());
            pse.push(i);
        }

        for(int i = n - 1; i >= 0; i--) {
            int curr = nums[i];

            while(!nse.empty() && nums[nse.top()] > curr) {
                nse.pop();
            }
            vecNSE[i] = (nse.empty()? n: nse.top());
            nse.push(i);
        }

        for(int i = 0; i < n; i++) {
            cnt = (cnt +  (1LL *  (i - vecPSE[i]) * (vecNSE[i] - i) * nums[i])) % mod;
        }

        return cnt;

        return cnt;
    }
};