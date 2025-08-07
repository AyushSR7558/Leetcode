class Solution {
private:
    int dp2[1000][1000];
    int dp3[1000][1000];

    // Child 1: diagonal path from (0,0) to (n-1,n-1)
    int ChildOne(vector<vector<int>>& fruits){
        int sum = 0;
        int n = fruits.size();
        for(int i = 0; i < n; i++){
            sum += fruits[i][i];
        }
        return sum;
    }

    // Child 2: from (0, n-1), stays in upper triangle (i < j)
    int ChildTwo(int i, int j, vector<vector<int>>& fruits) {
        int n = fruits.size();
        if(i >= n || j < 0 || j >= n || i >= j){
            return 0;
        }
        if(dp2[i][j] != -1) return dp2[i][j];

        int bottom = fruits[i][j] + ChildTwo(i + 1, j, fruits);
        int left = fruits[i][j] + ChildTwo(i + 1, j - 1, fruits);
        int right = fruits[i][j] + ChildTwo(i + 1, j + 1, fruits);

        return dp2[i][j] = max({bottom, left, right});
    }

    // Child 3: from (n-1, 0), stays in lower triangle (i > j)
    int ChildThree(int i, int j, vector<vector<int>>& fruits) {
        int n = fruits.size();
        if(i >= n || i < 0 || j >= n || i <= j){
            return 0;
        }
        if(dp3[i][j] != -1) return dp3[i][j];

        int upLeft = fruits[i][j] + ChildThree(i - 1, j + 1, fruits);
        int right = fruits[i][j] + ChildThree(i, j + 1, fruits);
        int down = fruits[i][j] + ChildThree(i + 1, j + 1, fruits);

        return dp3[i][j] = max({upLeft, right, down});
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        // Initialize dp arrays with -1
        memset(dp2, -1, sizeof(dp2));
        memset(dp3, -1, sizeof(dp3));

        int child1 = ChildOne(fruits);
        int child2 = ChildTwo(0 , n - 1, fruits);
        int child3 = ChildThree(n - 1, 0, fruits);

        return child1 + child2 + child3;
    }
};
