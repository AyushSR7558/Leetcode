class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int result = 0;
        bool requireEven = true;
        int count = 0;
        for(int x : nums) {
            if((x & 1) == 0 && requireEven) {
                count++;
                requireEven = false;
            }
            if((x & 1) && !requireEven) {
                count++;
                requireEven = true;
            }
        }
        result = max(count,result);
        count = 0;
        requireEven = false;
        for(int x : nums) {
            if((x & 1) == 0 && requireEven) {
                count++;
                requireEven = false;
            }
            if((x & 1) && !requireEven) {
                count++;
                requireEven = true;
            }
        }
        result = max(count,result);
        int evenCount = 0, oddCount = 0;
        for(int x : nums) {
            if(x & 1) {
                evenCount++;
            }else {
                oddCount++;
            }

        }
        result = max(max(evenCount,oddCount),result);
        return result;
    }
};