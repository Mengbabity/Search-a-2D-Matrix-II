class Solution {
private:
    bool DFS(vector<vector<int>>& matrix, int target,int i,int j,int m,int n)
    {
        char c;
        if(matrix[i][j]==target)
            return true;
        
        if(matrix[i][j]<target)
        {
            c=matrix[i][j];
            matrix[i][j]=-1;
            if(i+1<m && DFS(matrix,target,i+1,j,m,n))
                return true;
            
            if(j+1<n && DFS(matrix,target,i,j+1,m,n))
                return true;
            
            matrix[i][j]=c;       
        }
        
        if(matrix[i][j]>target)
        {
            if(i-1>=0 && matrix[i-1][j]==-1 && j-1>=0 && matrix[i][j-1]=='a')
                return false;
            
            if(i-1>=0 && matrix[i-1][j]!=-1 && DFS(matrix,target,i-1,j,m,n))
                return true;
            
            if(j-1>=0 && matrix[i][j-1]!=-1 && DFS(matrix,target,i,j-1,m,n))
                return true;
        }
        
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0)
            return false;
        int n=matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(DFS(matrix,target,i,j,m,n))
                    return true;
            }
        }
        
        return false;
    }
};
