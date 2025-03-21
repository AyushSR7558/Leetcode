class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row, col, mid,start,end;

        row = matrix.size();
        col = matrix[0].size();
        start = 0;
        end = row * col - 1;

        mid = start + (end -start)/2;

        while(start <= end){
            int element = matrix[mid/col][mid%col];

            if(element == target){
                return 1;
            }else if(element <= target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end -start)/2;
        }
        return 0;
    }
};