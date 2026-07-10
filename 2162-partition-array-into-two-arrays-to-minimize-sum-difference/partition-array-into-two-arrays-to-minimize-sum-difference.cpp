/*
Here's a solution that has the same underlying concept, but builds on it with some modifications to make the calculation a little easier. The idea is that instead of storing raw sums, store the net sums (i.e. if the first half has 8 numbers and we've calculated the sum of three of them, subtract the sum of the other 5). So say an array has 16 elements, the left side ("a") has the net sum of 3 elements, then we're looking for the right side ("b") with the net sum of 5 elements. In that case, (a + b) represents the net sum of a total of 8 elements and we want this to be as close to 0 as possible. So, a + b = 0, or b = -a. Hence for a given 'size', for each element 'a' on the LHS, we find the number closest to '-a' in RHS for size (m - size). Once we've found it, we find the minimum value of a + b.
*/

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int i, j, n = nums.size();
        int m = n / 2;
        vector<vector<int>> left(m + 1), right(m + 1);
        for (i = 0; i < (1 << m); i++) {
            int sum_left = 0;
            int sum_right = 0;
            int size = 0;
            for (j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    size++;
                    sum_left += nums[j];
                    sum_right += nums[j + m];
                }
                else {
                    sum_left -= nums[j];
                    sum_right -= nums[j + m];
                }
            }
            left[size].push_back(sum_left);
            right[size].push_back(sum_right);
        }
        for (auto &arr : right)
            sort(arr.begin(), arr.end());
        int ret = 1e9;
        for (int size = 0; size <= m; size++) {
            for (auto &a : left[size]) {
                auto &rhs = right[m - size];
                auto it = lower_bound(rhs.begin(), rhs.end(), -a);
                if (it != rhs.end()) {
                    ret = min(ret, abs(a + *it));
                }
                if (it != rhs.begin()) {
                    ret = min(ret, abs(a + *prev(it)));
                }
            }
        }
        return ret;        
    }
};