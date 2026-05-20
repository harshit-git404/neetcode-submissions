class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(n-1,dp,nums);
    }
    int solve(int n, vector<int>& dp, vector<int>& nums){
        if(n==0){
            dp[n]=nums[0];
            return dp[n];
        }
        if(n<0) return 0;
        
        if(dp[n]!=-1) return dp[n];

        return dp[n]=max(solve(n-1,dp,nums),solve(n-2,dp,nums)+nums[n]);
    }
};