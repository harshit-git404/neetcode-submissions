class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longest=0;
        for(int x:s){
            if(s.count(x-1)) continue;
            else{
                int i=1;
                while(true){
                    if(s.count(x+(i))) i++;
                    else break;
                }
                if(i>longest) longest=i;
            }
        }
        return longest;
    }
};