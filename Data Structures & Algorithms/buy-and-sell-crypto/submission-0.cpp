class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=1;
        int maxP=0;
        while(r<prices.size()){
            if(prices[l]>=prices[r]){
                l=r;
            }
            else{
                int profit=prices[r]-prices[l];
                maxP=max(maxP,profit);
            }
            r++;
        }
        return maxP;
    }
};