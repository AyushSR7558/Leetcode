class Solution {
private:
    vector<vector<int>> generateNinty(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> m(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[j][n - 1 - i] = mat[i][j];
            }
        }
        return m;
    }

    bool check(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool istrue = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) {
                    istrue = false;
                }
            }
        }
        return istrue;
    }

    void print(vector<vector<int>> &mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(check(mat, target)) return true;
        
        vector<vector<int>> temp = generateNinty(mat);

        if(check(temp, target)) return true;
        temp = generateNinty(temp);
        if(check(temp,target)) return true;
        temp = generateNinty(temp);
        if(check(temp,target)) return true;

        return false;
    }
};