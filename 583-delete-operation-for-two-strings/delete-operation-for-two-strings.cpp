
class Solution {
public:
    int solve(int i,int j,string&word1,string&word2,vector<vector<int>>&dp){
        if(i <= 0 || j <= 0) return 0; 
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i-1] == word2[j-1]){
            return dp[i][j] = 1 + solve(i-1,j-1,word1,word2,dp);
        }else{
            return dp[i][j] = max(solve(i-1,j,word1,word2,dp),solve(i,j-1,word1,word2,dp));
        }
    }
    int minDistance(string word1, string word2) {
        int w1 = word1.size(),w2 = word2.size(); 
        vector<vector<int>>dp(w1+1,vector<int>(w2+1,-1));
        int n = solve(w1,w2,word1,word2,dp); 
        return w1+w2 - 2*n;  
    }
};