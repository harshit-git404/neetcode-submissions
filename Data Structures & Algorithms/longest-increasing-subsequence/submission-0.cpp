class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int maxLIS=1;
        //check every starting point cause recur gives answer considering i is starting point
        //but in {5,1,2,3,4} 5 need not be starting point, LIS is 1,2,3,4 -> 1 is starting point
        for(int i=0;i<n;i++){
            maxLIS=max(maxLIS,recur(nums,dp,i));
        }
        return maxLIS;
    }
    int recur(vector<int>& nums, vector<int>& dp, int i){
        if(dp[i]!=-1) return dp[i];
        int LIS=1;
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]<nums[j])
                LIS=max(LIS,1+recur(nums,dp,j));
        }
        return dp[i]=LIS;
    }
};