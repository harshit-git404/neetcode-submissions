class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        //[3,3] -> doesnt store {3,0}, only {3,1}
        //does not require storing all values
        //for this nextloop, if we looped reverse it would fail as there's nothing for {3,1}
        for(int i=0;i<nums.size();i++){
            int search=target-nums[i];
            if(mp.count(search)&&mp[search]!=i){
                return {i,mp[search]};
            }
        }
        return {-1,-1};
    }
};