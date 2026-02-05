class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for(int i = 0; i < n; i++) {
            int temp = nums[i];
            bool isNeg = temp < 0;
            temp = abs(temp) % n;
            if(isNeg) temp = -temp;
            if(nums[i] == 0) {
                result.push_back(0);
                continue;
            }
            int indx = i + temp;
            if(indx < 0) indx += n;
            cout << indx;
            result.push_back(nums[indx % n]);
        }
        return result;
    }
};