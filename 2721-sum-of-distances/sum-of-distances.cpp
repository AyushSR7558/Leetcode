class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        long long n = nums.size(); // Size of nums
        unordered_map<long long, vector<long long>> mp; // To store the indx
        unordered_map<long long, vector<long long>> prefixSum; // To store prefix sum

        // Store  feq to reference it in future
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            prefixSum[nums[i]].push_back((prefixSum[nums[i]].empty()? 0: prefixSum[nums[i]].back()) + i);
        }
        
        vector<long long> arr(n, 0);

        for(int i = 0; i < n; i++) {
            int sz = mp[nums[i]].size();
            auto it = upper_bound(mp[nums[i]].begin(), mp[nums[i]].end(), i) - mp[nums[i]].begin();
            arr[i] += it * i - prefixSum[nums[i]].at(it - 1);
            if(it != mp[nums[i]].size()) {
                arr[i] += prefixSum[nums[i]].back() - prefixSum[nums[i]].at(it - 1) - (sz - it) * i;
            }
        }
        return arr;
    }
};