class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    vector<int> dp(n+1,-1);
    return min(solve(n-1,dp,cost),solve(n-2,dp,cost));
    }
    int solve(int n,vector<int>& dp,vector<int>& cost){
        if(n<=1){
            dp[n]=cost[n];
            return dp[n];
        }
        if(dp[n]!=-1) return dp[n];

        dp[n]=min(cost[n]+solve(n-1,dp,cost),cost[n]+solve(n-2,dp,cost));
        return dp[n];
    }
};
