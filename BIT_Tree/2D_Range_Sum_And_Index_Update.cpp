#include<bits/stdc++.h>
using namespace std;

class BitTree {
public:
    int fen[1001][1001];
    int n,m;
    
    void update(int i,int j,int val)
    {
        int jj=j;
        while(i<=n)
        {
            j=jj;
            while(j<=m)
            {
                fen[i][j]+=val;
                j+=(j&(-j));
            }
            i+=(i&(-i));
        }
    }
    
    int sum(int i,int j)
    {
        int jj=j,ans=0;
        while(i>0)
        {
            j=jj;
            while(j>0)
            {
                ans+=fen[i][j];
                j-=(j&(-j));
            }
            i-=(i&(-i));
        }
        return ans;
    }
    
    BitTree(vector<vector<int>>& matrix) {
        int i,j;
        n=matrix.size();
        m=matrix[0].size();
        memset(fen,0,sizeof(fen));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                update(i+1,j+1,matrix[i][j]);
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {  // Sum inside submatrix from row1,col1 to row2,col2
        row1+=1;
        row2+=1;
        col1+=1;
        col2+=1;
        return sum(row2,col2)-sum(row1-1,col2)-sum(row2,col1-1)+sum(row1-1,col1-1);
        
        
    }
  
};

int main()
{
    long long int i,j,x,n,m;
    cin>>n;
    vector<vector<int>>v;
    for(i=0;i<n;i++)
    {
    	vector<int>v1;
    	for(j=0;j<m;j++)
    	{
	        cin>>x;
	        v1.push_back(x);
    	}
    	v.push_back(v1);
    }
    BitTree bt(v);

    
    
    
}
