class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0, bot=m-1;
        int row;
        while(top<=bot){
            row=(top+bot)/2;
            if(target>matrix[row][n-1]) top=row+1;    //not >=
            else if(target<matrix[row][0]) bot=row-1; //not <=
            else break;
        }
        if(top>bot) return false;
        
        int l=0, r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(target==matrix[row][mid]) return true;
            else if((target>matrix[row][mid])) l=mid+1;
            else r=mid-1;
        }

        return false;
    }
};