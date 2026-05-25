class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0; int maxLen=0; int len=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(s,i,j,dp)){
                    int len=j-i+1;
                    if(len>maxLen){
                        start=i;
                        maxLen=len;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
    bool isPal(string& s, int i, int j, vector<vector<bool>>& dp){
        if(i>=j) return true;
        //give true for (1)single char(always palindrome) and (2)when i excceeds j, just to stop recursing
        if(dp[i][j]) return true;
        if(s[i]==s[j]) return dp[i][j]=isPal(s,i+1,j-1,dp);
        return false;
    }
};
