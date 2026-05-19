class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        int fleet=0;
        double timePrev=0;
        for(auto p:v){
            double time=(double)(target-p.first)/p.second;
            if(time>timePrev){
                fleet++;
                timePrev=time;
            }
        }
        return fleet;
    }
};