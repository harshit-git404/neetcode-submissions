class Solution {
public:
    int rows, cols;
    vector<vector<int>> res;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows=heights.size();
        cols=heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool> (cols,false));
        vector<vector<bool>> atlantic(rows, vector<bool> (cols,false));

        for(int j=0;j<cols;j++){
            if(pacific[0][j]==false) dfs(heights, pacific,0,j);
        }
        for(int i=1;i<rows;i++){
            if(pacific[i][0]==false) dfs(heights, pacific,i,0);
        }
        for(int i=0;i<rows;i++){
            if(atlantic[i][cols-1]==false) dfs(heights, atlantic,i,cols-1);
        }
        for(int j=0;j<cols;j++){
            if(atlantic[rows-1][j]==false) dfs(heights, atlantic,rows-1,j);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(pacific[i][j]==true && atlantic[i][j]==true) res.push_back({i,j});
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &visited, int i, int j){
        if(visited[i][j]==true) return;
        visited[i][j]=true;

        if(i-1 >= 0 && heights[i-1][j] >= heights[i][j])
            dfs(heights, visited, i-1, j);
        if(i+1 < rows && heights[i+1][j] >= heights[i][j])
            dfs(heights, visited, i+1, j);
        if(j-1 >= 0 && heights[i][j-1] >= heights[i][j])
            dfs(heights, visited, i, j-1);
        if(j+1 < cols && heights[i][j+1] >= heights[i][j])
            dfs(heights, visited, i, j+1);

        return;
    }
};
