class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n + 1, true);
        v[0] = false;
        v[1] = false;
        for (int i = 2; i < n; i++) {
            if(v[i]== false) continue;
            for (int j = 2 * i; j <= n; j += i) {
                v[j] = false;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == true) {
                ans++;
            }
        }
        return ans;
    }
};