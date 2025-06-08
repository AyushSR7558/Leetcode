class Solution {
public:
    vector<int> dp;
    bool helper(vector<int> & arr, int idx,int end, vector<bool>& visited){
        if(idx< 0 || idx>=arr.size() || visited[idx]){
            return false;
        }
        if(idx==end || arr[idx] == 0){
            return true;
        }
        visited[idx] =true;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]= helper(arr,idx+arr[idx],end,visited) || helper(arr,idx-arr[idx],end,visited);
    }
    bool canReach(vector<int>& arr, int start) {
        int end = -1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) end =i;
        }
        if(end==-1) return false;

        vector<bool> visited(arr.size(),false);
        dp.resize(arr.size(),-1);
       return  helper(arr,start,end,visited);
    }
};