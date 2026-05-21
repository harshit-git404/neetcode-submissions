class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int index=coins.size()-1;
        vector<vector<int>> dp(index+1,vector<int>(amount+1,-1));
        return recur(coins,amount,index,dp);
    }
    //when counting solutions, return 1 when success 0 when fail in base case, soln is pick+noPick
    int recur(vector<int>& coins, int amount, int index,vector<vector<int>>& dp){
        //base case
        if(index==0){
            if(amount%coins[index]==0){
                return 1;
            }
            dp[index][amount]=0;
            return 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int pick=0;
        if(amount>=coins[index]){
            pick=recur(coins,amount-coins[index],index,dp);
        }
        int noPick=recur(coins,amount,index-1,dp);
        dp[index][amount]=pick+noPick;
        return pick+noPick;
    }
};