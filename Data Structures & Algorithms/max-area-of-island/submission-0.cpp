class Solution {
public:
    int rows, cols;
    int area;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows=grid.size();
        cols=grid[0].size();
        int maxArea = 0;
        vector<vector<bool>> visited (rows, vector<bool> (cols,false));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && visited[i][j]==false){
                    area=0;
                    dfs(grid,visited,i,j);
                    maxArea = max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j){
        if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j]==0) return;
        if(visited[i][j]) return;
        area++;
        visited[i][j]=true;

        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i,j-1);
        dfs(grid,visited,i,j+1);

        return;
    }
};