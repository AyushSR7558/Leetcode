class Solution {
private:
    int findFirstOccurance(vector<int>& nums, int target) {
        int  n = nums.size();

        int l = 0, r = n - 1, ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] == target) {
                ans = mid;
                r = mid - 1;
            }else if(nums[mid] < target) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }

        return ans;
    }

    int findLastOccurance(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n - 1, ans = -1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] == target) {
                ans = mid;
                l = mid + 1;
            }else if(nums[mid] < target) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }

        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurance = findFirstOccurance(nums, target), lastOccurance = findLastOccurance(nums, target);

        return {firstOccurance, lastOccurance};

    }
};