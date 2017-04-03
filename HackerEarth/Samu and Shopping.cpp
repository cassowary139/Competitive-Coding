#include <bits/stdc++.h>
using namespace std;
int dp[100005][3],n;
int a[100005][3];
int solve(int pos, int last)
{
    int i,ans;
    if(pos==0)
        return 0;
    if(dp[pos][last]!=-1)
        return dp[pos][last];
        ans = INT_MAX;
    for(i=0;i<3;i++)
    {
        if(last!=i)
            ans = min(ans,a[pos-1][i]+solve(pos-1,i));
    }
    return dp[pos][last]=ans;
}
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        memset(dp,-1,sizeof(dp));
        cout<<solve(n,-1)<<endl;
    }
    return 0;
}
