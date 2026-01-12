class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int travelTime = 0;
        int n = points.size();

        for(int i = 1; i < n; i++) {
            travelTime += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        }
        return travelTime;
    }
};