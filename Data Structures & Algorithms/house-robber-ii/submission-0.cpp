class Solution {
public:
    //use same code as house robber 1
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int> nums2(nums.begin()+1,nums.end());

        if(n==1) return nums[0];
        return max(solve(n-2,dp1,nums1),solve(n-2,dp2,nums2));
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