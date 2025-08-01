class Solution {
    vector<int> xDir = {-1,0,1,0};
    vector<int> yDir = {0,1,0,-1};
private:
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& vis,int m, int n, int x, int y){
        if(x < 0 || x >= m || y < 0 || y >= n) return ;
        if(board[x][y] == 'X') return;
        if(vis[x][y]) return;

        vis[x][y] = true;
        dfs(board,vis,m,n,x - 1, y);
        dfs(board,vis,m,n,x , y + 1);
        dfs(board,vis,m,n,x + 1, y);
        dfs(board,vis,m,n,x , y - 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                dfs(board,vis,m,n,0,i);
            }
            if(board[m - 1][i] == 'O'){
                dfs(board,vis,m,n,m-1,i);
            }
        }
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                dfs(board,vis,m,n,i,0);
            }
            if(board[i][n-1] == 'O'){
                dfs(board,vis,m,n,i,n-1);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && vis[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
};