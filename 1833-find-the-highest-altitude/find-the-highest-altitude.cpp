class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0, altitude = 0;

        for(int i = 0; i < gain.size(); i++) {
            altitude += gain[i];
            maxAltitude = max(maxAltitude, altitude);
        }

        return maxAltitude;
    }
};