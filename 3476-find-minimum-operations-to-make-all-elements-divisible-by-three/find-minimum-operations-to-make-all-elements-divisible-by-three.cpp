class Solution {
private:
    int minimumOperationsForSingleElement(int num) {
        if(num % 3 == 0) return 0;

        return min(abs((num / 3) * 3 - num), abs(((num + 3)/ 3) * 3 - num));
    }
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), totalOperations = 0;

        for(int i = 0; i < n; i++) {
            totalOperations += minimumOperationsForSingleElement(nums[i]);
        }

        return totalOperations;
    }
};