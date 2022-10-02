class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,j,n=s.length(),ans=0;
        i=0;
        j=0;
        unordered_map<char,int>mp;
        while(j<n)
        {
            mp[s[j]-'a']+=1;
            while(mp[s[j]-'a']>1 && i<j)
            {
                mp[s[i]-'a']-=1;
                i+=1;
            }
            ans=max(ans,j-i+1);
            j+=1;
        }
        return ans;
        
    }
};