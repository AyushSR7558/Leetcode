class Solution {
private:    
    int BinarySearch(vector<int>& arr, int k) {
        int l = 0, r = arr.size() - 1;

        while(l < r) {
            int mid = l + (r - l + 1) / 2;

            if(abs((mid + 1) - arr[mid]) >= k) {
                r = mid - 1;
            }else {
                l = mid;
            }
        }
        return l;
    }
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0] > k) return k;
        int indx = BinarySearch(arr, k);
        cout << indx;

        return arr[indx] + k - (arr[indx] - (indx + 1)) ;
    }
};