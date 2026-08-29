class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    int cycle=0;
    bool validTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        visited.resize(n,false);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0,0);
        if(cycle==1) return false;
        for(int i=0;i<n;i++){
            if(visited[i]==false) return false;
        }
        return true;
    }

    void dfs(int node, int parent){
        visited[node]=true;
        for(int neighbour:graph[node]){
            if(visited[neighbour]==true && neighbour!=parent){
                cycle=1;
                return;
            }
            if(visited[neighbour]==true && neighbour==parent) continue;
            dfs(neighbour,node);
        }
    }
};
