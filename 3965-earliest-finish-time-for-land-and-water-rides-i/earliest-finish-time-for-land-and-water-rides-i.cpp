class Solution {
private:
    int findEarliestFinish(vector<int>& firstStartTime,
                           vector<int>& firstDuration,
                           vector<int>& secondStartTime,
                           vector<int>& secondDuration) {
        int n = firstStartTime.size(), m = secondStartTime.size();

        // Find the earliest time we can finish any first-type ride
        int earliestFirstEnd = INT_MAX;
        for (int i = 0; i < n; i++) {
            earliestFirstEnd = min(earliestFirstEnd,
                                   firstStartTime[i] + firstDuration[i]);
        }

        // Now find the earliest finish for a second-type ride taken after
        int result = INT_MAX;
        for (int i = 0; i < m; i++) {
            int waitUntil = max(earliestFirstEnd, secondStartTime[i]);
            result = min(result, waitUntil + secondDuration[i]);
        }

        return result;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        return min(
            findEarliestFinish(landStartTime,  landDuration,
                               waterStartTime, waterDuration),
            findEarliestFinish(waterStartTime, waterDuration,
                               landStartTime,  landDuration)
        );
    }
};