class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp = {{(double)poured - 1}};

        if(poured <= 1) {
            return (query_row > 0? 0: poured);
        }

        for(int i = 1; i <= query_row; i++) {
            vector<double> curr(i + 1);
            for(int j = 0; j <= i; j++) {
                if(j == 0) {
                    curr[j] = dp[i - 1][j] / 2.0;
                }else if(j == i) {
                    curr[j] = dp[i - 1][j - 1] / 2;
                }else {
                    curr[j] = (dp[i - 1][j] + dp[i - 1][j - 1]) / 2;
                }

                if(i == query_row && j == query_glass) {
                    return min(1.0 , curr[j]);
                }
                curr[j] = (curr[j] > 1? curr[j] - 1: 0);
            }
            dp.push_back(curr);
        }

        for(int i = 0; i < dp.size(); i++) {
            for(int j = 0; j < dp[i].size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return min(dp[query_row][query_glass], 1.0);
    }
};