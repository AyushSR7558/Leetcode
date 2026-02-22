class NumArray {
vector<int> arr;
vector<int> seg;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arr.resize(n);
        seg.resize(4 * n);
        for(int i = 0; i < n; i++) {
            arr[i] = nums[i];
        }
        build(0, n - 1, 0);
    }
    
    void update(int index, int val) {
        helper(0, arr.size() - 1, index, val, 0);
        
    }


    void helper(int low, int high, int indx, int val, int i) {
    if (low == indx && high == indx) {
        seg[i] = val;   // correct: update this node
        arr[indx] = val;
        return;
    }

    int mid = (low + high) >> 1;

    if (indx <= mid) {
        helper(low, mid, indx, val, 2 * i + 1);
    } else {
        helper(mid + 1, high, indx, val, 2 * i + 2);
    }

    // recalculate after update
    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}
    void build(int low, int high, int indx) {
        if(low == high) {
            seg[indx] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;
        build( low, mid, indx * 2 + 1);
        build( mid + 1, high, indx * 2 + 2);
        seg[indx] = seg[indx *2 + 1] + seg[indx * 2 + 2];
    }

    int helperSum(int left, int right, int low, int high, int indx) {
        if(low >= left &&  right >= high) {
            return seg[indx];
        }
        if(right < low || left > high) {
            return 0;
        }

        int mid = (low + high) >> 1;
        return helperSum(left, right, low, mid, indx * 2 + 1) + helperSum(left, right, mid + 1, high, indx * 2 + 2);
    }
    
    int sumRange(int left, int right) {
        return helperSum(left, right, 0, arr.size() - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */