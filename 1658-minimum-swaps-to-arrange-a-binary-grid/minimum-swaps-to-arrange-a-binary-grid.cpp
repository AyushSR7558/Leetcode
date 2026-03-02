class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> num(n);

        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                cnt++;
            }
            num[i] = cnt;
        }

        for(int a : num) {
            cout << a << " ";
        }

        int cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            if(num[i] >= n - 1 - i) continue;
            bool istrue = false;
            for(int j = i + 1; j < n; j++) {
                if(num[j] >= n - 1 - i) {
                    cnt += j - i;
                    for(int k = j - 1; k >= i; k--) {
                        swap(num[k], num[k + 1]);
                    }
                    istrue = true;
                    break;
                }
            }
            if(!istrue) return -1;
        }
        
        return cnt;
    }
};