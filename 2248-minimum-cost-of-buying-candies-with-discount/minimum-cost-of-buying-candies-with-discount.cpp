class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        int cnt = 0;
        sort(cost.begin(), cost.end());

        for(int i = n - 1; i >= 0;) {
            if(i == 0) {
                cnt += cost[0];
                break;
            }

            cnt += cost[i] + cost[i - 1];
            i -= 3;
        }

        return cnt;
    }
};