#include <bits/stdc++.h>
using namespace std;
int dp[6101][6101];
int LCS(string a,string b,int n)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][n];
}
int main()
{
    int t,n;
    string a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        n = a.length();
        string b(a);
        reverse(b.begin(),b.end());
        cout<<n - LCS(a,b,n)<<endl;
    }
    return 0;
}
