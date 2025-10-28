class Solution {
private:
    bool leftPath(vector<int> nums, int pos) {
        int n = nums.size();
        bool leftDir = true;
        for (int i = pos; i >= 0 && i < n;) {
            if (nums[i] > 0) {
                nums[i]--;
                if (leftDir) {
                    leftDir = false;
                } else {
                    leftDir = true;
                }
            }

            if (leftDir) {
                i--;
            } else {
                i++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return false;
        }
        return true;
    }
    bool rightPath(vector<int> nums, int pos) {
        int n = nums.size();
        bool rightDir = true;
        for (int i = pos; i >= 0 && i < n;) {
            if (nums[i] > 0) {
                nums[i]--;
                if (rightDir) {
                    rightDir = false;
                } else {
                    rightDir = true;
                }
            }

            if (rightDir) {
                i++;
            } else {
                i--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return false;
        }
        return true;
    }
    int possiblePath(vector<int> nums, int pos) {
        int pathSum = 0;
        if (rightPath(nums, pos))
            pathSum++;
        if (leftPath(nums, pos))
            pathSum++;
        return pathSum;
    }

public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int totPathSum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                totPathSum += possiblePath(nums, i);
            }
        }
        return totPathSum;
    }
};