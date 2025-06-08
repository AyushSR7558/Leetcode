class Solution {
public:
    int n;
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        n = grid.size();
        return  helper(grid,0,0,1);
    }
    vector<vector<int>> dir = {{2,-1},{1,2},{-2,-1},{2,1},{-2,1},{-1,-2},{-1,2},{1,-2}};
    bool helper(vector<vector<int>>& grid,int i, int j,int cell){
        for(vector<int> d:dir){
            int newI = i+d[0], newJ = j+d[1];
            if(newI<n && newJ<n && newI>=0 && newJ>=0 && grid[newI][newJ] ==cell  ){
                return helper(grid,newI,newJ,cell+1);
            }
        }
        return cell==n*n;
    }
};