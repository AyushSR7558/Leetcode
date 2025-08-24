class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int p = satisfaction.size();
        vector<int> positiveNo, negativeNo;
        for(int i = 0; i < p; i++) {
            if(satisfaction[i] < 0) {
                negativeNo.push_back(satisfaction[i]);
            }else {
                positiveNo.push_back(satisfaction[i]);
            }
        }
        sort(negativeNo.begin(), negativeNo.end());
        sort(positiveNo.begin(), positiveNo.end());

        int maxiSatisfaction = INT_MIN;
        int m = negativeNo.size(), n = positiveNo.size();
        for(int i = 0; i < m; i++) {
            int coefficient = 1, satisfactionLevel = 0;
            for(int j = i; j < m; j++) {
                satisfactionLevel += coefficient * negativeNo[j];
                coefficient++;
            }
            for(int j = 0; j < n; j++) {
                satisfactionLevel += coefficient * positiveNo[j];
                coefficient++;
            }
            maxiSatisfaction = max(maxiSatisfaction, satisfactionLevel);
        }
        int satisfactionLevel = 0;
        for(int i = 0; i < n; i++) {
            satisfactionLevel += positiveNo[i] * (i + 1);
        }
        maxiSatisfaction = max(maxiSatisfaction, satisfactionLevel);
        return maxiSatisfaction;
    }
};