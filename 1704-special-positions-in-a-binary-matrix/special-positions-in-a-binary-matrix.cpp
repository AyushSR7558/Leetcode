class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            cout << row[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++) {
            cout << col[i] << " ";
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] && row[i] == 1 && col[j] == 1) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};