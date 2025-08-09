class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftPtr = 0, rightPtr = nums.size() - 1;
        while(leftPtr <= rightPtr){
            int mid = leftPtr + (rightPtr - leftPtr) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target){
                leftPtr = mid + 1;
            } else {
                rightPtr = mid - 1;
            }   
        }
        return -1;
    }
};