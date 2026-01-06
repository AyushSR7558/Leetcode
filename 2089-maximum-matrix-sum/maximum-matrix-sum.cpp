class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negCount = 0, n = matrix.size();
        long long sum = 0;
        int val = INT_MAX;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] < 0) negCount++;
                if(abs(matrix[i][j]) < val) {
                    val = abs(matrix[i][j]);
                }
                sum += abs(matrix[i][j]);
            }
        }
        
        if(negCount % 2) {
            sum -= 2 * val;
        }
        return sum;
    }
};