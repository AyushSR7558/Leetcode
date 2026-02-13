class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); // The length of the vector
        int cnt = 0; // Count the Total water collected

        /*
            * We will find the greatest element from the right
            * We will find the greatest element from the left
            * Calculate the sum of curVal - min(leftGreatest, rightGreatest) over all the indexes in the vector
        */
        vector<int> r(n); // To Store the Greatest Element from the right
        vector<int> l(n); // To Find the Greatest Element from the left

        int maxi = height[n - 1];
        for(int i = n - 1; i >= 0; i--) {
            maxi = max(height[i], maxi);
            r[i] = maxi; 
        }

        maxi = height[0];
        for(int i = 0; i < n; i++) {
            maxi = max(height[i], maxi);
            l[i] = maxi;
        }

        for(int i = 0; i < n; i++) {
            cnt += min(r[i],l[i]) - height[i];
        }
        return cnt;
    }
};