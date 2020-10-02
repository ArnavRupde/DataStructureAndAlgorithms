#include<bits/stdc++.h>
using namespace std;
 
string number;
 
long long int dp[9][81][2];
long long int getAns(long long int index,long long int sum,bool isEdge)
{
    long long int count=0,curr_digit,temp,i;
    if(isEdge)
        temp=1;
    else
        temp=0;
    if (dp[index][sum][temp]!=-1)
        return dp[index][sum][temp];
    if (index==number.length()-1)
    {
        if(sum>9)
            count=0;
        else if(!isEdge)
            count=1;
        else{
            curr_digit=number[index]-'0';
            if (sum>curr_digit)
                count=0;
            else
                count=1;
        }
    }
    else if(isEdge)
    {
        curr_digit=number[index]-'0';
        for(i=0;i<curr_digit&&sum>=i;i++)
            count+=getAns(index+1,sum-i,false);
        if (sum>=curr_digit)
            count+=getAns(index+1,sum-curr_digit,true);
 
    }
    else
    {
        for(i=0;i<=9&&sum>=i;i++)
            count+=getAns(index+1,sum-i,false);
 
    }
    dp[index][sum][temp]=count;
    return count;
 
 
}
 
int main()
{
    long long int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79};
    long long int n,i,j,k,ans,maxlen,t,a,b,ans1,ans2;
    n=sizeof(primes)/sizeof(primes[0]);
    ans=0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<81;j++)
        {
            for(k=0;k<2;k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
 
    cin>>t;
    while(t--)
    {
        // cout<<"inside "<<t<<endl;
        cin>>a>>b;
        a-=1;
        memset(dp,-1,sizeof(dp));
        number = to_string(a);
        // cout<<"a-1 "<<number<<endl;
        ans1=0;
        maxlen=number.length();
        for(i=0;i<n&&primes[i]<=maxlen*9;i++)
            ans1+=getAns(0,primes[i],true);
        ans2=0;
        // cout<<"Answer "<<ans1<<endl;
        number = to_string(b);
        // cout<<"b "<<number<<endl;
        maxlen=number.length();
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n&&primes[i]<=maxlen*9;i++)
            ans2+=getAns(0,primes[i],true);
        // cout<<"ans2 "<<ans2<<endl;
        cout<<ans2-ans1<<endl;
 
    }
 
    // cin>>number;
    // maxlen=number.length();
    // for(i=0;i<n&&primes[i]<=maxlen*9;i++)
    // {   
    // ans2=getAns(0,primes[i],true);
    //     ans+=ans2;
    //     cout<<" for "<<primes[i]<<" "<<ans2<<endl;
 
    // }
    // cout<<ans<<endl;
    
} 