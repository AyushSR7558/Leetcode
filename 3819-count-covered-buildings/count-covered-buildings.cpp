class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>>row_const(n + 1, vector<int>(2,-1)),col_const(n + 1, vector<int>(2,-1));
        for(int i = 0; i < buildings.size(); i++){
            int x = buildings[i][0];
            int y = buildings[i][1];
            if(row_const[x][0] == -1){
                row_const[x][0] = y;
            }else{
                row_const[x][0] = min(y,row_const[x][0]);
            }
            if(col_const[y][0] == -1){
                col_const[y][0] = x;
            }else{
                col_const[y][0] = min(x, col_const[y][0]);
            }
            row_const[x][1] = max(y,row_const[x][1]);
            col_const[y][1] = max(x,col_const[y][1]);
        }
        int count = 0;
        for(int i = 0; i < buildings.size(); i++){
            int x = buildings[i][0];
            int y = buildings[i][1];
            if(x > col_const[y][0] && x < col_const[y][1] && y > row_const[x][0] && y < row_const[x][1])
{
                count++;
            }
        }
        return count;
    }
};