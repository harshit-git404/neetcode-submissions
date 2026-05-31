class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmin=1, currmax=1;
        //not 1, as it fails for {-2} -> 1 is wrong, ans is -2
        int res=nums[0];
        for(int num:nums){
            int tmp=num*currmax;
            currmax=max(max(num*currmax,num*currmin),num);
            currmin=min(min(num*currmin,tmp),num);
            res=max(res,currmax);
        }
        return res;
    }
};