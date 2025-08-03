class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> mp;
        int mini = INT_MAX;
        int n = basket1.size();

        // Count frequency difference
        for(int i = 0; i < n; i++) {
            mp[basket1[i]]++;
            mini = min(mini, basket1[i]);
        }
        for(int i = 0; i < n; i++) {
            mp[basket2[i]]--;
            mini = min(mini, basket2[i]);
        }

        vector<int> extra;
        for(auto& entry : mp) {
            int fruit = entry.first;
            int diff = entry.second;
            if(diff == 0) continue;
            if(diff & 1) return -1; // odd frequency = not possible
            for(int i = 0; i < abs(diff) / 2; i++) {
                extra.push_back(fruit);
            }
        }

        sort(extra.begin(), extra.end());
        long long result = 0;
        for(int i = 0; i < extra.size() / 2; i++) {
            result += min(1LL * mini * 2, 1LL * extra[i]);
        }

        return result;
    }
};
