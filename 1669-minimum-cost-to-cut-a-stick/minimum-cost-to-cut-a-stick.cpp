class Solution {
private:
    int helper(vector<int>& cuts, int st, int ed, vector<vector<int>>& dp) {
        // Base case
        if(st == ed) {
            return 0; // There is no more stick to cut
        }

        if(dp[st][ed] != -1) return dp[st][ed];
        int minCost = INT_MAX;

        for(int i = st; i < ed; i++) {
            minCost = min(minCost, helper(cuts, st, i, dp) + helper(cuts, i + 1, ed, dp) + cuts[ed] - cuts[st - 1]);
        }
        return dp[st][ed] = minCost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<int> temp;
        temp.push_back(0);
        for(int i = 0; i < cuts.size(); i++) temp.push_back(cuts[i]);
        temp.push_back(n);
        vector<vector<int>> dp(temp.size() + 1, vector<int>(temp.size() + 1, -1));
        return helper(temp, 1, temp.size() - 1, dp);
    }
};