class Solution {
private:
int sort(vector<int> &nums, int lIndx, int rIndx) {
    int mid = lIndx + (rIndx - lIndx) / 2;
    vector<int> temp;
    int lptr = lIndx, rptr = mid + 1;
    int lptr2 = lptr;
    int rptr2 = rptr;
    int inversionCount = 0;
    while(lptr2 <= mid && rptr2 <= rIndx){
        if((long long)nums[lptr2] > nums[rptr2] * 2LL){
            inversionCount += mid - lptr2 + 1;
            rptr2++;
        }else{
            lptr2++;
        }
    }
    while(lptr <= mid && rptr <= rIndx){
        if(nums[lptr] < nums[rptr]) {
            temp.push_back(nums[lptr]);
            lptr++;
        } else {
            temp.push_back(nums[rptr]);
            rptr++;
        }
    }
    while(lptr <= mid) {
        temp.push_back(nums[lptr]);
        lptr++;
    }
    while(rptr <= rIndx) {
        temp.push_back(nums[rptr]);
        rptr++;
    }
    for(int i = 0; i < temp.size(); i++, lIndx++){
        nums[lIndx] = temp[i];
    }
    return inversionCount;
}
int mergeSort(vector<int> &nums,int lIndx, int rIndx){
    if(lIndx == rIndx) {
        return 0;
    }
    int midIndx = lIndx + (rIndx - lIndx) / 2, inversionCount = 0;
    inversionCount += mergeSort(nums, lIndx, midIndx);
    inversionCount += mergeSort(nums, midIndx + 1, rIndx);
    inversionCount += sort(nums, lIndx, rIndx);
    return inversionCount;
}
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};