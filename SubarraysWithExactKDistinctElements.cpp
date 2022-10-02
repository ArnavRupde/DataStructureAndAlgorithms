#include <bits/stdc++.h>
using namespace std;

 int maxKSubarray(vector<int>& v, int k)
{
    int i=0,j=0,ans=0,n=v.size();
    unordered_map<int,int> mp;
    for(j=0;j<n;j++)
    {
        if(mp[v[j]]==0)
        {
            k-=1;
        }
        mp[v[j]]+=1;
        while(k<0)
        {
            mp[v[i]]-=1;
            if(mp[v[i]]==0)
                k+=1;
            i+=1;
        }
        ans+=(j-i+1);
    }
    return ans;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    // Exact K distinct element subarrays =
    // At Most K distinct element subarrays -
    // At most K-1 distinct element subarrays
    return maxKSubarray(nums,k) - maxKSubarray(nums,k-1);
}

int main()
{
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout<<subarraysWithKDistinct(nums,k)<<endl;
}
