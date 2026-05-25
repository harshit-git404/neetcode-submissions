class Solution {
public:
    //ditto ques as previous, reused code fully
    int count =0;
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(s,i,j,dp)) count++;
            }
        }
        return count;
    }
    bool isPal(string& s, int i, int j, vector<vector<bool>>& dp){
        if(i>=j) return true;
        //give true for (1)single char(always palindrome) and (2)when i excceeds j, just to stop recursing
        if(dp[i][j]) return true;
        if(s[i]==s[j]) return dp[i][j]=isPal(s,i+1,j-1,dp);
        return false;
    }
};