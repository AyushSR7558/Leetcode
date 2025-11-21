class Solution {
public:
    int uperbound(int x, vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int lowerbound(int x, vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {

        vector<int> candind;

        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '|')
                candind.push_back(i);
        }
        int q = queries.size();
        vector<int> ans(q, 0);
        for (int i = 0; i < q; i++) {
            auto ub = uperbound(queries[i][0], candind);
            auto lb = lowerbound(queries[i][1], candind);
            int plates = 0;
            if (lb >= 0 && ub >= 0 && lb < candind.size() &&
                ub < candind.size())
                plates = candind[lb] - candind[ub] - 1 - (lb - ub - 1);
            if (plates > 0)
                ans[i] = plates;
        }
        return ans;
    }
};