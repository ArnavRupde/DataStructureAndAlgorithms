#include<bits/stdc++.h>
using namespace std;

int ans=INT_MIN;


int lcs(string s1,string s2,int m,int n){
    int dp[m + 1][n + 1];  
    
    
    for (int i = 0; i <= m; i++)  
    {  
        for (int j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            dp[i][j] = 0;  
      
        else if (s1[i - 1] == s2[j - 1])  
            dp[i][j] = dp[i - 1][j - 1] + 1;  
      
        else
            dp[i][j] = 0;  


        //update answer
        if(dp[i][j]>ans){ans=dp[i][j];}

        }  
    }  
    return ans;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    
    int m=s1.length();
    int n=s2.length();
    

    
    cout<<lcs(s1,s2,m,n)<<"\n";
    
    return 0;
}


//s1=OldSite:GeeksforGeeks.org
//s2=NewSite:GeeksQuiz.com
//op==10