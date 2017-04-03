#include <bits/stdc++.h>
using namespace std;
int a[50],m[50],n;
int dp[1<<15][51];
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int solve(int p,int mask)
{
    int ans=0;
    if(p==n)
        return 0;
    if(dp[mask][p]!=-1)
        return dp[mask][p];
    ans = max(ans,solve(p+1,mask));
            if((mask&m[p])==0){
    ans = max(ans,1+solve(p+1,mask|m[p]));
    }
    return dp[mask][p]=ans;
}
int main()
{
    int t,i,j;
    long long int k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            k=0;
            for(j=0;j<15;j++)
            {
                if((a[i]%prime[j])==0)
                {
                k = k|(1<<j);
                }
            }
                m[i]=k;
            }
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0)<<endl;
    }
    return 0;
}
