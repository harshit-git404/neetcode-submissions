class Solution {
public:
    vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1); //cause nodes aren't 0 to n-1, they are 1 to n.....
        vector<int> ans;
        for(int i=0; i<n; i++) parent[i]=i;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(find(u)==find(v)){
                ans=edge;
            }
            else unite(u,v);
        }
        return ans;
    }

    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            parent[b]=a;
        }
    }
};