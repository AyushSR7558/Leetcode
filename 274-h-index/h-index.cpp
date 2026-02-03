class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h_index = 0;
        int n = citations.size();

        sort(citations.begin(), citations.end());

        for(int i = 1; i <= n; i++) {
            if((citations.end() - lower_bound(citations.begin(), citations.end(), i) )>= i) {
                h_index = i;
            }
        }
        return h_index;
    }
};