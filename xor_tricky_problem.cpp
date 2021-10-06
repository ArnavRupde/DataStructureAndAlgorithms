//given an array of N integers. All Integers are present in even count except one.
//find that one integer which has odd count in O(N) time complexity and O(1) space;
//N < 10^5 
//a[i] < 10^5

//logic => take XOR or all elements 

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int ans = 0;
  for(int i=0;i<n;i++){
    cin>>x;
    ans^=x;
  }
  cout<<ans;
 return 0;  
}