#include<bits/stdc++.h>
using namespace std;

long long int n;
vector<long long int>nums;
long long int Seg[2000005];
long long int Upd[2000005];

void build(long long int idx,long long int lo,long long int hi)
{
    if(lo==hi)
    {
        Seg[idx]=nums[lo];
        return;
    }
    long long int mid=lo+(hi-lo)/2;
    build(2*idx+1,lo,mid);
    build(2*idx+2,mid+1,hi);
    Seg[idx]=Seg[2*idx+1]+Seg[2*idx+2];
}

long long int getSum(long long int idx,long long int lo,long long int hi,long long int left,long long int right)
{
    if(Upd[idx]!=0)
    {
        long long int val=Upd[idx];
        long long int cnt=hi-lo+1;
        Seg[idx]+=cnt*val;
        Upd[idx]=0;
        Upd[2*idx+1]+=val;
        Upd[2*idx+2]+=val;
    }
    
    if(lo>right || hi<left)
        return 0;
    if(lo>=left && hi<=right)
        return Seg[idx];
    long long int mid=lo+(hi-lo)/2;
    return getSum(2*idx+1,lo,mid,left,right)+getSum(2*idx+2,mid+1,hi,left,right);
}

void update(long long int idx,long long int lo,long long int hi,long long int left,long long int right,long long int val)
{
    if(Upd[idx]!=0)
    {
        long long int val1=Upd[idx];
        long long int cnt=hi-lo+1;
        Seg[idx]+=cnt*val1;
        Upd[idx]=0;
        Upd[2*idx+1]+=val1;
        Upd[2*idx+2]+=val1;
    }
    
    if(lo>right || hi<left)
        return;
    if(lo>=left && hi<=right)
    {
        Seg[idx]+=val*(hi-lo+1);
        if(lo!=hi)
            Upd[2*idx+1]+=val,Upd[2*idx+2]+=val;
        return;
    }
    long long int mid=lo+(hi-lo)/2;
    update(2*idx+1,lo,mid,left,right,val);
    update(2*idx+2,mid+1,hi,left,right,val);
    Seg[idx]=Seg[2*idx+1]+Seg[2*idx+2];
    
}

int main()
{
    long long int i,j,q,p,a,b,u,k,qtype;
    cin>>n>>q;
    for(i=0;i<n;i++)
    {
        cin>>p;
        nums.push_back(p);
    }
    build(0,0,n-1);
    while(q--)
    {
        cin>>qtype;
        if(qtype==1)
        {
            cin>>a>>b>>u;
            a-=1;
            b-=1;
            update(0,0,n-1,a,b,u);
        }
        else{
            cin>>k;
            k-=1;
            cout<<getSum(0,0,n-1,k,k)<<endl;
        }
    }
    
}
