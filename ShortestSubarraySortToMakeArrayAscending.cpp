class Solution {
public:
    // Count length of shortest subarray which when sorted makes array ascending
    int findUnsortedSubarray(vector<int>& nums) {
        int i,j,n=nums.size();
        int mn=INT_MAX,mx=INT_MIN;
        int strt=-1,endd;
        for(i=n-1;i>=0;i--)
        {
            if(nums[i]<mn)
                mn=nums[i];
            if(nums[i]>mn)
                strt=i;
        }
        for(i=0;i<n;i++)
        {
            if(nums[i]>mx)
                mx=nums[i];
            if(nums[i]<mx)
                endd=i;
        }
        if(strt==-1)
            return 0;
        else
            return endd-strt+1;
        
        
        
    }
};