class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        long long lsum = 0, rsum = 0;
        
        while(l < n - 1 && nums[l] < nums[l + 1]) {
            lsum += nums[l];
            l++;
        }

        while(r > 0 && nums[r] < nums[r - 1]) {
            rsum += nums[r];
            r--;
        }
        cout << l << " " << r << " " << lsum << " " << rsum;

        if(l == r) {
            long long opt1 = abs((lsum + nums[l]) - rsum);
            long long opt2 = abs((lsum) - (rsum + nums[l])) ;
            return min(opt1, opt2);
        }else if(r - l == 1 && nums[l] == nums[r]) {
            return abs(lsum - rsum);
        }else return -1;
    }
};