class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    int countComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        visited.resize(n,false);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                count++;
                dfs(i);
            }
        }
        return count;
    }
    void dfs(int node){
        visited[node]=true;
        for(int neighbour:graph[node]){
            if(!visited[neighbour])
                dfs(neighbour);
        }
    }
};