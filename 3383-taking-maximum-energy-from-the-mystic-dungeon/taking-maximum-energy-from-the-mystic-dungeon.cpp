class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> finalEnery(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            finalEnery[i] = energy[i] + (i + k < n? finalEnery[i + k]: 0);
        }
        return *max_element(finalEnery.begin(), finalEnery.end());
    }
};