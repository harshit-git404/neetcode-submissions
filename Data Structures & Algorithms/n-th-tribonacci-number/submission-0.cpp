class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=0;
        return recur(dp,n);
    }
    int recur(vector<int>& dp,int i){
        if(i<0) return 0;
        if(i==1||i==2) return dp[i]=1;
        if(dp[i]!=-1) return dp[i];

        return dp[i]=recur(dp,i-1)+recur(dp,i-2)+recur(dp,i-3);
    }
};