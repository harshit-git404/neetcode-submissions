class Solution {
public:
    vector<int> dr = {-1,1,0,0};
    vector<int> dc = {0,0,-1,1};
    const int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> res(row,vector<int>(col,10000));
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> node=q.front();
            int x=node.first;
            int y=node.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=x+dr[k];
                int nc=y+dc[k];
                if(nr>=0 && nc>=0 && nr<row && nc<col){
                    if(grid[nr][nc]!=-1){
                        if(res[nr][nc]>res[x][y]+1){
                            res[nr][nc]=res[x][y]+1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!=-1){
                    grid[i][j]=res[i][j];
                    if(grid[i][j]==10000) grid[i][j]=INF;
                }
            }
        }
    }
};
