#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<long long> createDiffArray(const vector<int>& stations, int r) {
        int n = stations.size();
        vector<long long> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            diff[L] += stations[i];
            if (R + 1 < n) diff[R + 1] -= stations[i];
        }
        return diff;
    }

    bool can(long long X, const vector<long long>& power, int r, long long k) {
        int n = power.size();
        vector<long long> diffExtra(n + 1, 0);
        long long used = 0, extra = 0;

        for (int i = 0; i < n; i++) {
            extra += diffExtra[i];
            long long curPower = power[i] + extra;

            if (curPower < X) {
                long long need = X - curPower;
                used += need;
                if (used > k) return false;

                extra += need;
                int endIdx = i + 2 * r + 1;
                if (endIdx < n) diffExtra[endIdx] -= need;
            }
        }
        return true;
    }

    long long giveMid(long long l, long long r) { return l + (r - l) / 2; }

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        vector<long long> diff = createDiffArray(stations, r);
        vector<long long> power(n);
        power[0] = diff[0];
        for (int i = 1; i < n; i++)
            power[i] = power[i - 1] + diff[i];

        long long low = 0;
        long long high = *max_element(power.begin(), power.end()) + k;
        long long ans = 0;

        while (low <= high) {
            long long mid = giveMid(low, high);
            if (can(mid, power, r, k)) {
                ans = mid;          
                low = mid + 1;
            } else {
                high = mid - 1;     
            }
        }
        return ans;
    }
};
