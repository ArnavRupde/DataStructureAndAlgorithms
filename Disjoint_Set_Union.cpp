#include<bits/stdc++.h>
using namepsace std;

int par[100005];
int rank[100005];

int getpar(int p)
{
    if(par[p]==p)
        return p;
    else
        return getpar(par[p]);
}
void union_it(int x,int y)
{
    int x1=getpar(x);
    int y1=getpar(y);
    if(x1==y1)
        return;
    if(rank[x1]<rank[y1])
        par[x1]=y1;
    else if(rank[x1]>rank[y1])
        par[y1]=x1;
    else
    {
        par[x1]=y1;
        rank[y1]+=1;
    }
}

int main()
{
    int i,j,n;
    for(i=0;i<n;i++)
    {
        par[i]=i;
        rank[i]=1;
    }
    // union_it(x,y)  -> Adds Set x and y  -> Also Update Rank for balancing
    // getpar(x)      -> Find parent of x
}
