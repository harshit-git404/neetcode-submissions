class Solution {
public:
    int m,n;
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        for(int j=0;j<n;j++) dfs(board,0,j);
        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][n-1]=='O') dfs(board,i,n-1);
        }
        for(int j=0;j<n;j++) dfs(board,m-1,j);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n) return;
        if(grid[i][j]=='X' || grid[i][j]=='Y') return;
        grid[i][j]='Y';

        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);

        return;
    }
};