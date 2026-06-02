class Solution {
private:
    int helper(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int minTimeReq = INT_MAX;

        // If we take the land ride first
        int minStartTime = INT_MAX, minEndTime = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (minEndTime >= landStartTime[i]) {
                minEndTime = min(minEndTime, landStartTime[i] + landDuration[i]);
            }
        }

        minTimeReq = INT_MAX;

        for (int i = 0; i < m; i++) {
            if (waterStartTime[i] <= minEndTime) {
                minTimeReq = min(minEndTime + waterDuration[i], minTimeReq);
            } else {
                minTimeReq =
                    min(minTimeReq, waterStartTime[i] + waterDuration[i]);
            }
        }
        return minTimeReq;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
                            return min(helper(landStartTime, landDuration, waterStartTime, waterDuration), helper( waterStartTime, waterDuration,landStartTime, landDuration ) );
 
    }
};