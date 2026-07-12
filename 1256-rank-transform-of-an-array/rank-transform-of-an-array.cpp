class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        if(n == 0) return {};

        vector<int> rank(n);
        vector<pair<int, int>> temp;

        for(int i = 0; i < n; i++) {
            temp.push_back({arr[i], i});
        }

        sort(temp.begin(), temp.end());
        int r = 1;

        rank[temp[0].second] = 1;
        
        for(int i = 1; i < n; i++) {
            int pos = temp[i].second, val = temp[i].first;
            if(val != temp[i - 1].first) r++;
            rank[pos] = r;
        }

        return rank;
    }
};