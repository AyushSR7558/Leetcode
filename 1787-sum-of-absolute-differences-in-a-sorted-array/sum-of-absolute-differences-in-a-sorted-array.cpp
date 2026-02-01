class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();        
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int count = 0;
            count += prefix[n - 1] - prefix[i] - (n - i - 1) * nums[i];
            count += (i + 1) * nums[i] - prefix[i]; 
            cout << count << endl;
            res.push_back(count);
        }
        return res;

    }
};