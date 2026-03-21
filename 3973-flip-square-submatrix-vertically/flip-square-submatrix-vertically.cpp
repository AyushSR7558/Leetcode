class Solution {
public:
        vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> nums = grid;
        int stRow, edRow, Col;
        stRow = x;
        edRow = x + k - 1;
        Col = y + k;
        for(; stRow < m && edRow < m && stRow < edRow; stRow++, edRow--) {
            for(int j = y; j < n && j < Col; j++) {
                swap(nums[stRow][j],nums[edRow][j]);
            }
        }
        return nums; 
    }
};