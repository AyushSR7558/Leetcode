class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<int> temp;
        long long pts = 0;

        for(int i = 0; i < n; i++) {
            if(technique1[i] >= technique2[i]) {
                k--;
            }else {
                temp.push_back( - technique1[i] + technique2[i]);
            }
            pts += max(technique1[i], technique2[i]);
        }
        if(k <= 0) return pts;
        sort(temp.begin(), temp.end());

        for(int i = 0; i < k; i++) {
            pts -= temp[i];
        }
        return pts;
    }
};