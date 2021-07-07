#include<bits/stdc++.h>
using namespace std;
 
vector<long long int>Seg[100000];
vector<long long int>nums;
 
void merge(long long int idx)
{
    long long int i=0,j=0,n1=Seg[2*idx+1].size(),n2=Seg[2*idx+2].size();
    while(i<n1 && j<n2)
    {
        if(Seg[2*idx+1][i]<Seg[2*idx+2][j])
        {
            Seg[idx].push_back(Seg[2*idx+1][i]);
            i+=1;
        }
        else{
            Seg[idx].push_back(Seg[2*idx+2][j]);
            j+=1;
        }
    }
    while(i<n1)
    {
        Seg[idx].push_back(Seg[2*idx+1][i]);
        i+=1;
    }
    while(j<n2)
    {
        
        Seg[idx].push_back(Seg[2*idx+2][j]);
        j+=1;
    }
}
 
void build(long long int idx, long long int lo,long long int hi)
{
    // cout<<"idx lo hi"<<idx<<lo<<hi<<endl;
    if(lo==hi)
    {
        Seg[idx].push_back(nums[lo]);
        return;
    }
    long long int mid=lo+(hi-lo)/2;
    build(2*idx+1,lo,mid);
    build(2*idx+2,mid+1,hi);
    // cout<<"at index="<<idx<<endl;
    merge(idx);
    // cout<<"Seg Became"<<endl;
    // for(int i=0;i<Seg[idx].size();i++)
    //     cout<<Seg[idx][i]<<" ";
    // cout<<endl;
}
 
long long int count(long long int idx,long long int k)
{
    if(Seg[idx].size()==0)
        return 0;
    long long int idx1=lower_bound(Seg[idx].begin(),Seg[idx].end(),k+1)-Seg[idx].begin();
    if(idx1>=Seg[idx].size())
        return 0;
    return Seg[idx].size()-idx1;
}
 
long long int query(long long int idx,long long int lo,long long int hi,long long int left,long long int right,long long int k)
{
    if(lo>=left && hi<=right)
        return count(idx,k);
    if(lo>right || hi<left)
        return 0;
    long long int mid=lo+(hi-lo)/2;
    return query(2*idx+1,lo,mid,left,right,k)+query(2*idx+2,mid+1,hi,left,right,k);
}
 
int main()
{
    long long int i,j,n,p,q,a,b,k;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>p;
        nums.push_back(p);
    }
    build(0,0,n-1);
    cin>>q;
    while(q--)
    {
        cin>>a>>b>>k;
        a-=1;
        b-=1;
        cout<<query(0,0,n-1,a,b,k)<<endl;
    }
}
