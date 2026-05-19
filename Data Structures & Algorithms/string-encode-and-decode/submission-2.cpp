class Solution {
public:

    string encode(vector<string>& strs) {
        string str="";
        for(string s:strs){
            str+=to_string(s.size())+"#"+s;
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i=0;
        while(i<s.size()){
            int j;
            for(j=i;;j++){
                if(s[j]=='#') break;
            }
            int num=stoi(s.substr(i,j-i));
            
            string sub=s.substr(j+1,num);
            decoded.push_back(sub);
            
            i=j+num+1;
        }
        return decoded;
    }
};
