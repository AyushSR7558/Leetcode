class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ab = nums[0], n=nums.size();
        for(int i=1;i<n;i++){
            ab  =ab^ nums[i];
        }
        int idx =0 ;
        for(int i=0;i<31;i++){
            if(ab& (1<<i)){
                break;
            }
            idx++;
        }
        cout<<idx;
        int a =0;
        int b =0;
        for(int i=0;i<n;i++){
            if(nums[i] & (1<<idx)){
                a^=nums[i];
            }
            else{
                cout<<nums[i]<<" ";
                b^=nums[i];
            }
        }
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};