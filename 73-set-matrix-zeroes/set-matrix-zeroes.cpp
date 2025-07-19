class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>vecRows, vecCols;
    int rows = matrix.size(), cols = matrix[0].size();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == 0){
                vecRows.insert(i);
                vecCols.insert(j);
            }
        }
    }
    for(auto a : vecRows){
        for(int i = 0; i < cols; i++){
            matrix[a][i] = 0;
        }
    }
    for(auto a : vecCols){
        for(int i = 0; i < rows; i++){
            matrix[i][a] = 0;
        }
    }
    return ;
    }
};