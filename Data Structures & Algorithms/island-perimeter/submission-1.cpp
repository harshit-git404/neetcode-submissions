class Solution {
public:
    int rows, cols;

    int islandPerimeter(vector<vector<int>>& grid) {
        rows=grid.size();
        cols=grid[0].size();
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) return dfs(grid,visited,i,j);
            }
        }
        return 0;
    }
    int dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j){
        
        if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j]==0) return 1;
        if(visited[i][j]) return 0;
        visited[i][j]=true;

        int a=dfs(grid,visited,i-1,j);
        int b=dfs(grid,visited,i+1,j);
        int c=dfs(grid,visited,i,j-1);
        int d=dfs(grid,visited,i,j+1);

        return a+b+c+d;
    }
};