class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0,j=0,id=-1,ip=-1;
        int n=s.size();
        int m=p.size();
        
        while(i<n){
            if(j<m && s[i]==p[j]){
                i++;
                j++;
            }
            else if(j<m && p[j]=='?'){
                i++;
                j++;
            }
            else if(j<m && p[j]=='*'){
                id=i;
                ip=j;
                j++;
            }
            else if(ip!=-1){
                i=id+1;
                j=ip+1;
                id++;
            }
            else{
                return false;
            }
        }
        
        while(j<m && p[j]=='*'){
            j++;
        }
        
        if(j==m){
            return true;
        }
        return false;
    }
};