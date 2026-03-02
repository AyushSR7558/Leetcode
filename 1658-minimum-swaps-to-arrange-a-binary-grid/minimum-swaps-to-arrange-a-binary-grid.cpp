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
        unordered_set<int> st;
        for(int i = 0; i < n - 1; i++) {
            bool istrue = false;
            int temp = 0;
            for(int j = 0; j < n; j++) {
                if(st.count(j)) continue;
                if(num[j] >= n - 1 - i) {
                    st.insert(j);
                    cnt += temp;
                    istrue = true;
                    break;
                }
                temp++;
            }
            if(!istrue) {
                return -1;
            }
        }
        
        return cnt;
    }
};