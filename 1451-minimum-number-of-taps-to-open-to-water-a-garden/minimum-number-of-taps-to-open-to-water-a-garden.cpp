#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;
        for (int i = 0; i <= n; i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            intervals.push_back({start, end});
        }
        
        // Correct step: Sort the intervals by their starting points.
        sort(intervals.begin(), intervals.end());

        int taps = 0;
        int current_reach = 0;
        int max_reach = 0;

        int i = 0;
        while (current_reach < n) {
            // Find the best tap from the current position
            while (i < intervals.size() && intervals[i].first <= current_reach) {
                max_reach = max(max_reach, intervals[i].second);
                i++;
            }

            // If we can't reach any farther, it's impossible to water the garden.
            if (max_reach <= current_reach) {
                return -1;
            }

            // Open the new tap and update our reach.
            taps++;
            current_reach = max_reach;
        }

        return taps;
    }
};