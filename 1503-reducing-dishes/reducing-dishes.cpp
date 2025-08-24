class Solution {
// Now we will do this with the help of the recursion and dp
// This type of problem comes under the topic named kanpsack
private:
    int helper(vector<int>& satis, int time, int indx, vector<vector<int>>& dp) {
        if(indx >= satis.size()) return 0;
        if(dp[indx][time] != -1) return dp[indx][time];

        //We can either take or we can either not make the dish
        int take = -1e5, notTake = -1e5;
        take = satis[indx] * time + helper(satis, time + 1, indx + 1, dp);
        notTake = helper(satis, time, indx + 1, dp);
        return dp[indx][time] = max(take,notTake);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 2,-1));
        int val = helper(satisfaction, 1, 0, dp);
        return val < 0? 0: val;
    }
};