class Solution {
public: 
    int getFirstSmallerOrEqualt(vector<int>& nums1, int val, int indx) {
        int n = nums1.size();
        int ans = -1;
        int l = 0, r = min(indx, n - 1);

        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            if(nums1[mid] <= val) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size();
        int dist = 0;

        for(int i = 0; i < m; i++) {
            int indx = getFirstSmallerOrEqualt(nums1, nums2[i], i);
            if(indx != -1)
                dist = max(dist, i - indx);
        }
        return dist;
    }
};