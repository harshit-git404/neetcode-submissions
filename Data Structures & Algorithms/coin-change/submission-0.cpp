class Solution {
public:
    //just store whenever returning (memoization)
    int coinChange(vector<int>& coins, int amount) {
        int index=coins.size()-1;
        vector<vector<int>> dp(index+1,vector<int>(amount+1,-1));
        int ans=recur(coins,amount,index,dp);
        return (ans<1e9)?ans:-1;
    }
    int recur(vector<int>& coins, int amount, int index,vector<vector<int>>& dp){
        //base case
        if(index==0){
            if(amount%coins[index]==0){
                dp[index][amount]=amount/coins[index];
                return amount/coins[index];
            }
            dp[index][amount]=(int)(1e9);
            return (int)(1e9);
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int pick=(int)(1e9);
        if(amount>=coins[index]){
            pick=1+recur(coins,amount-coins[index],index,dp);
        }
        int noPick=recur(coins,amount,index-1,dp);
        dp[index][amount]=min(pick,noPick);
        return min(pick,noPick);
    }
};

      //non-memoized solution (TLE error)
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int index=coins.size()-1;
//         int ans=recur(coins,amount,index);
//         return (ans<1e9)?ans:-1;
//     }
//     int recur(vector<int>& coins, int amount, int index){
//         //base case
//         if(index==0){
//             if(amount%coins[index]==0){
//                 return amount/coins[index];
//             }
//             return (int)(1e9);
//         }
//         int pick=(int)(1e9);
//         if(amount>=coins[index]){
//             pick=1+recur(coins,amount-coins[index],index);
//         }
//         int noPick=recur(coins,amount,index-1);
//         return min(pick,noPick);
//     }
// };