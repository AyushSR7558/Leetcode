#define ll long long
class Solution {
private:
    ll binarySearch(vector<int>& potions, long long sucess, int nums) {
        ll l = 0, r = potions.size() - 1;
        int finalIndx = potions.size() ;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if((double)potions[mid] >= (double)sucess / nums) {
                r = mid - 1;
                finalIndx = mid;
            }else {
                l = mid + 1;
            }
        }
        return finalIndx;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ll n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++) {
            int indx = binarySearch(potions, success, spells[i]);
            ans[i] = m - indx;
        }
        return ans;
    }
};