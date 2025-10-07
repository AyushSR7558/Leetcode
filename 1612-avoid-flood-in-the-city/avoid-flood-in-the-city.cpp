#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> mp; // lake -> last day it was filled
        set<int> dryDays;           // indices of available dry days
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            int lake = rains[i];

            if (lake == 0) {
                dryDays.insert(i);
                ans[i] = 1; // placeholder
            } else {
                if (mp.count(lake)) {
                    int lastRainDay = mp[lake];
                    auto it = dryDays.upper_bound(lastRainDay);
                    if (it == dryDays.end()) {
                        return {};
                    }

                    int dryDay = *it;
                    ans[dryDay] = lake;
                    dryDays.erase(it); 
                }

                mp[lake] = i;
                ans[i] = -1;
            }
        }

        return ans;
    }
};
