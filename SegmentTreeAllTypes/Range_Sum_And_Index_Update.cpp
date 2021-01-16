#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int t[800000],n;
    void build(vector<int>& a, int v, int tl, int tr)
    {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    void updateSeg(int v, int tl, int tr, int pos, int new_val)
    {
        if (tl == tr)
        {
            t[v] = new_val;
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                updateSeg(v*2, tl, tm, pos, new_val);
            else
                updateSeg(v*2+1, tm+1, tr, pos, new_val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    int sumSeg(int v, int tl, int tr, int l, int r)
    {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sumSeg(v*2, tl, tm, l, min(r, tm))
               + sumSeg(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    SegmentTree(vector<int>& nums) {
        n=nums.size();
        build(nums,1,0,n-1);
        // cout<<"build successful"<<endl;
        
    }
    
    void update(int index, int val) {
        updateSeg(1,0,n-1,index,val);
        
        
    }
    
    int sumRange(int left, int right) {
        return sumSeg(1,0,n-1,left,right);
        
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,j,a,b,x,n,q,qtype;
    cin>>n>>q;
    vector<int>v;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    SegmentTree st(v);
    while(q--)
    {
        cin>>qtype>>a>>b;
        if(qtype==1)
        {
            a-=1;
            st.update(a,b);
        }
        else
        {
            a-=1;
            b-=1;
            cout<<st.sumRange(a,b)<<endl;
        }
    }
    
}
