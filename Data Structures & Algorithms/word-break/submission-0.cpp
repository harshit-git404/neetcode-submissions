class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //bool dp is awkward here, as we need -1=not computed, 0=return false, 1=return true
        vector<int> dp(s.size(),-1);
        return (recur(s,wordDict,dp,0))?true:false;
    }
    int recur(string& s, vector<string>& wordDict, vector<int>& dp, int i){
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        //try for all words starting from index i, if match then start i beyond that word
        for(string word:wordDict){
            int len=word.size();
            // if(i+len<=s.size() && s.substr(i,len)==word)       wrong as if the path fails(0) you return immediately,
            //     return dp[i]=recur(s,wordDict,dp,i+len);       you need to try all possibilities
            if(i+len<=s.size() && s.substr(i,len)==word){
                if(recur(s,wordDict,dp,i+len)) return dp[i]=1;
            }
        }
        //return 0 only when all words didnt match from that index
        return dp[i]=0;
    }
};