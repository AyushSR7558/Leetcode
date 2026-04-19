class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }

        // Clear stack
        while (!st.empty())
            st.pop();

        // Next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] + 1;
            int side = min(arr[i], width);
            ans = max(ans, side * side);
        }

        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> col(n, 0); // Consecutive zero in col

        int area = 0;

        for (int i = 0; i < m; i++) {
            int h = INT_MAX, w = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] - '0') {
                    col[j]++;
                } else {
                    col[j] = 0;
                }
            }
            area = max(area, maxProduct(col));
            cout << area << endl;
            for (int k = 0; k < n; k++) {
                cout << col[k] << " ";
            }
            cout << endl << endl;
        }
        return area;
    }
};