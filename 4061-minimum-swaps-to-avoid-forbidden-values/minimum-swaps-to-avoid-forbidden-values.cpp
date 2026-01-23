class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int a = nums.size();
        unordered_map<int, int> n, f, matching;
        int cnt = 0, maxi = 0;

        for(int i = 0; i < a; i++) {
            if(nums[i] == forbidden[i]) {
                cnt++;
                matching[nums[i]]++;
                maxi = max(matching[nums[i]], maxi);
            }
            n[nums[i]]++; f[forbidden[i]]++;
        }

        for(auto& p : n) {
            if(a - p.second < f[p.first]) return -1;
        }

        return max(maxi, (cnt + 1)/ 2);
    }
};