class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int r=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]){
                    if(i==0||j==0){
                        r++;
                        continue;
                    }
                    int mini = min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]));
                    r+=1+mini;
                    matrix[i][j]+=mini;
                }
            }
        }
        return r;
    }
};
