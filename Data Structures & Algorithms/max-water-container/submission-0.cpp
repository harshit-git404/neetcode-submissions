class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1;
        int maxW=0;
        while(l<r){
            maxW=max(maxW,(r-l)*min(height[l],height[r]));
            (height[l]>height[r])?r--:l++;
        }
        return maxW;
    }
};