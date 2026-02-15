class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt = 0;// This is count the number of intervals to be remove
        int lastfree = 0;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        lastfree = intervals[0][1];
        cnt = 1;
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] >= lastfree) {
                lastfree = intervals[i][1];
                cnt++;
            }
        }
        return intervals.size() - cnt;
    }
};