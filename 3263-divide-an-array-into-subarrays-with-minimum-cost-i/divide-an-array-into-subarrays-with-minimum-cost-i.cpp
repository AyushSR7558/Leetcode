class Solution {
public:
    int minimumCost(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        int sum = nums[0];
         for(int i = 0; i < 2; i++) {
            sum += pq.top();
            pq.pop();
         }
         return sum;
    }
};