#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int t[800000]={0},n;
	

	void updateSeg(int v, int tl, int tr, int l, int r,int u)
    {
        if (l > r) 
            return;
        if (l == tl && r == tr) {
			t[v]+=u;
            return;
        }
        int tm = (tl + tr) / 2;
        updateSeg(v*2, tl, tm, l, min(r, tm),u);
		updateSeg(v*2+1, tm+1, tr, max(l, tm+1), r,u);
    }

	int getVal(int v, int tl, int tr, int pos)
    {
        if (tl == tr && tr==pos)
        {
            return t[v];
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                return t[v]+getVal(v*2, tl, tm, pos);
            else
                return t[v]+getVal(v*2+1, tm+1, tr, pos);
        }
    }

    SegmentTree(vector<int>& nums) {
        n=nums.size();
        // build(nums,1,0,n-1);
        // cout<<"build successful"<<endl;
        
    }
    
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,j,a,b,c,x,n,q,qtype;
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
        cin>>qtype;
        if(qtype==1)
        {
			//  Add c in Range (a,b)
			cin>>a>>b>>c;
            a-=1;
			b-=1;
            st.updateSeg(1,0,n-1,a,b,c);
        }
        else
        {
			// Get Value at index a
			cin>>a;
            a-=1;
            cout<<v[a]+st.getVal(1,0,n-1,a)<<endl;
        }
    }
    
}
