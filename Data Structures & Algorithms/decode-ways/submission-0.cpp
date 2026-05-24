class Solution {
public:
    int numDecodings(string s) {
        int i=0;
        vector<int> dp(s.size(),-1);
        return count(s, i, dp);
    }
    int count(string& s, int i, vector<int>& dp){
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        if(stoi(s.substr(i,1))==0) return 0;
        bool valid2=false;
        if(i<s.size()-1){
            if(!(stoi(s.substr(i,2))<10 || stoi(s.substr(i,2))>26)) valid2=true;
        }
        
        return dp[i]=count(s,i+1,dp) + ((valid2) ? count(s,i+2,dp) : 0);
    }
};