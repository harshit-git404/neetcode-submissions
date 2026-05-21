class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<nums.size();i++){
            currSum=max(nums[i],currSum+nums[i]);
            maxSum=max(currSum,maxSum);
        }
        return maxSum;
    }
};

                //previous approach that failed for negative numbers
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int currSum=0;
//         int maxSum=0;
//         if(nums.size()==1) return nums[0];
//         for(int n:nums){
//             if(currSum<0){
//                 currSum=0;
//             }
//             currSum+=n;
//             maxSum=max(maxSum,currSum);
//         }
//         return maxSum;
//     }
// };