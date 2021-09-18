#include<bits/stdc++.h>
using namespace std;

class BitTree {
public:
    long long int n;
    long long int fen[100005]; // 1 Based Indexing used
    
    void update(long long int i,long long int val)
    {
        while(i<=n)
        {
            fen[i]+=val;
            i+=(i&(-i));
        }
    }
    
    long long int sum(long long int i) //returns prefix sum upto index i
    {
        long long int ans=0;
        while(i>0)
        {
            ans+=fen[i];
            i-=(i&(-i));
        }
        return ans;
    }
  
  BitTree(vector<long long int>& nums) {
        n=nums.size();
        long long int i;
        for(i=0;i<=n;i++)
          fen[i]=0;
        for(i=0;i<n;i++)
          update(i+1,nums[i]);
        
    }
  
};

int main()
{
    long long int i,j,x,n;
    cin>>n;
    vector<long long int>v;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    BitTree bt(v);
  
    // Query from index l to r inclusive 0 <=l,r< n => sum(r+1)-sum(l)
    
    
}
