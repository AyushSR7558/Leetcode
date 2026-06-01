class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        int cnt = 0;
        sort(cost.begin(), cost.end());

        for(int i = n - 1; i >= 0;) {
            if(i >= 1) {
                cnt += cost[i] + cost[i - 1];
                i -= 3;
            }else {
                cnt  += cost[i];
                i -= 1;
            }
        }

        return cnt;
    }
};