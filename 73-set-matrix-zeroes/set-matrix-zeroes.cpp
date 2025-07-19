class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> copy = matrix;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(copy[i][j] == 0) {
                    for(int k = 0; k < cols; k++) matrix[i][k] = 0;
                    for(int k = 0; k < rows; k++) matrix[k][j] = 0;
                }
            }
        }
    }
};
