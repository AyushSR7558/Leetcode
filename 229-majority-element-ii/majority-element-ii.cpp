class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); // n store the size of the nums
        unordered_map<int,int> mp; // This map will store the frequency of the element 
        //We will iterate through the nums and update the frequencies in the map dataStructure
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        int reqFreq = n / 3; // count will store the element whose frequency is greater than n / 3 i.e, reqFreq
        vector<int> eleGreaterThanReqFreq;
        for(auto ele : mp){
            if(ele.second > reqFreq){
                eleGreaterThanReqFreq.push_back(ele.first);
            }
        }
        return eleGreaterThanReqFreq;
    }
};