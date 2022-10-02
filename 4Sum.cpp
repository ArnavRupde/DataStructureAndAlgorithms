class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<int,vector<pair<int,int>>>mp;
        int i,j,n=nums.size(),k,su,rem,sz,x,y;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                su=nums[i]+nums[j];
                mp[su].push_back({i,j});
            }
        }
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                su=nums[i]+nums[j];
                rem=target-su;
                // cout<<i<<" "<<j<<endl;
                sz=mp[rem].size();
                // cout<<sz<<endl;
                for(k=0;k<sz;k++)
                {
                    x=mp[rem][k].first;
                    y=mp[rem][k].second;
                    if(i!=x && i!=y && j!=x && j!=y)
                    {
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[x]);
                        v.push_back(nums[y]);
                        sort(v.begin(),v.end());
                        st.insert(v);
                    }
                }
            }
        }
        for(auto it=st.begin();it!=st.end();it++)
            ans.push_back(*it);
        return ans;
    }
};