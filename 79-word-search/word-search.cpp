class Solution {
private:
    bool check(vector<vector<char>>& board, string word,int indx, int i , int j, vector<vector<bool>>& visited) {
        if(indx == word.size()) return true;
        int n = board.size(), m = board[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        if(visited[i][j] == true) return false;
        if(board[i][j] != word[indx]) return false;
        visited[i][j] = true;
        //Now we have four ways that are up, down, right, left
        bool up = check(board,word,indx + 1,i - 1, j,visited);
        bool down = check(board,word,indx + 1, i + 1, j, visited);
        bool right = check(board, word, indx + 1,i, j + 1, visited);
        bool left = check(board, word, indx + 1, i, j - 1, visited);
        visited[i][j] = false;

        return up || down || right || left;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool isTrue = false;
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                isTrue = check(board,word,0,i,j,visited);
                if(isTrue) break;
            }
            if(isTrue) break;
        }
        return isTrue;
    }
};