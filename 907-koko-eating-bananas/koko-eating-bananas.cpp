class Solution {
private:
    bool isPossible(vector<int>& piles,int h, int speed) {
        int count = 0;
        for(int i = 0; i < piles.size(); i++) {
            count += (piles[i] + speed - 1) / speed;
            if(count > h) return false;
        }
        return true;
    }
    int BinarySearch(vector<int>& piles, int h, int low, int high) {
        int ansIndx = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(piles,h,mid)) {
                ansIndx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ansIndx;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(),piles.end());
        return BinarySearch(piles,h,1,maxi);
    }
};