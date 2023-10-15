class Solution {
public:
    string minWindow(string s, string t) {
        int i,j,n=s.length(),m=t.length();
        unordered_map<char,int>mp;
        unordered_set<char>st;
        for(i=0;i<m;i++)
        {
            mp[t[i]]+=1;
            st.insert(t[i]);
        }
        string ans="";
        int len=0,sz=INT_MAX;
        unordered_map<char,int>curr;
        i=0;
        for(j=0;j<n;j++)
        {
            curr[s[j]]+=1;
            if(curr[s[j]]>=mp[s[j]])
                st.erase(s[j]);
            while(i<=j && curr[s[i]]>mp[s[i]])
            {
                curr[s[i]]-=1;
                i+=1;
            }
            if(st.size()==0)
            {
                if(i<=j)
                {
                    len=j-i+1;
                    if(len<sz)
                    {
                        sz=len;
                        ans=s.substr(i,len);
                    }
                }
            }
        }
        return ans;
        
    }
};