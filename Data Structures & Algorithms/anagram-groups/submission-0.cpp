class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(const string& s : strs){
            string sortedS = s;
            sort(sortedS.begin(),sortedS.end());
            mp[sortedS].push_back(s);
        }
        vector<vector<string>> res;
        for(auto pair:mp){
            res.push_back(pair.second);
        }
        return res;
    }
};