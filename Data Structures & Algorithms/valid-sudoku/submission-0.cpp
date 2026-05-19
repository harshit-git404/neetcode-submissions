class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> rows,cols;
        map<pair<int,int>,unordered_set<char>> square;
        //unordered map needs a hash for its key, int has hash, but not pair
        for(int r=0;r<9;r++){
            for (int c=0;c<9;c++){
                char ch=board[r][c];
                if(ch=='.') continue;
                else{
                    if(rows[r].count(ch)||cols[c].count(ch)||square[{r/3,c/3}].count(ch)){
                        return false;
                    }
                    else{
                        rows[r].insert(ch);
                        cols[c].insert(ch);
                        square[{r/3,c/3}].insert(ch);
                    }
                }
            }
        }
        return true;
    }
};