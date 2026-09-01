class Solution {
public:
    vector<int> dr = {-1,1,0,0};
    vector<int> dc = {0,0,-1,1};

    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int minutes=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> node=q.front();
                int x=node.first;
                int y=node.second;
                
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=x+dr[k];
                    int nc=y+dc[k];
                    if(nr>=0 && nc>=0 && nr<row && nc<col){
                        if(grid[nr][nc]==1){
                            grid[nr][nc]=2;
                            q.push({nr,nc});
                        }
                    }
                }
            }
            if(!q.empty())
                minutes++;
        }
        for(int i=0; i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minutes;
    }
};