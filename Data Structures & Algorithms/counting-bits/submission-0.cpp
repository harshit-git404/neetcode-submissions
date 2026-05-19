class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++){
            int num=i;
            while(num){
                num=num&(num-1);
                ans[i]++;
            }
        }
        return ans;
    }
};