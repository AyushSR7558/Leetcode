class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st, end,mid;

        mid =(st + end) /2;

        st = 0;
        end = nums.size() - 1;

        while(st <= end){
            if(nums[mid] == target) return mid;
            //left sorted
            if(nums[st] <= nums[mid]){
                if(target < nums[mid] && target >= nums[st]){
                    end = mid -  1;
                }else{
                    st = mid + 1;
                }
            }else{
                if(target > nums[mid] && target <= nums[end]){
                    st = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
            mid = (st + end)/2;
        }
        return -1;
    }
};