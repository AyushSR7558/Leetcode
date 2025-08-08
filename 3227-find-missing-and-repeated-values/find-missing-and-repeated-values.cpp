class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long a, b, sum = 0 , sqrSum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += grid[i][j];
                sqrSum += grid[i][j] * grid[i][j];
            }
        }
        long long firstNSqr = (n * 1LL * n) * (n * n * 1LL * 2 + 1) * (n * n + 1) / 6;
        long long a_b = sqrSum - firstNSqr;
        long long res = (sum - ((n * n) * (n * n+ 1) / 2));
        a_b = (a_b / res);
        a = (a_b + res) / 2;
        b = res - a;
        return {(int)a,(int)-b};
    }
};