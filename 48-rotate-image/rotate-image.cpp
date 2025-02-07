class Solution {
public:
    void MakeTranspose(vector<vector<int>>& array, int row, int col){
        for(int i = 0; i < row; i++){
            for(int j = i + 1; j < col; j++){
                swap(array[i][j],array[j][i]);
            }
        }
    }

    void ReverseTheRow(vector<vector<int>>&array, int row, int col){
        for(int i = 0; i < row; i++){
            int start = 0;
            int end = col - 1;

            while(start < end){
                swap(array[i][start],array[i][end]);
                start++;
                end--;
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int row, col;

        row =  matrix.size();
        col = matrix[0].size();

        MakeTranspose(matrix,row,col);

        ReverseTheRow(matrix,row,col);
        
    }
};