#include <bits/stdc++.h>
using namespace std;
int rc(int p[],int n,int r[])
{
    int ans;
    if(r[n]>=0)
        return r[n];
    else
    {
        ans=-1;
        for(int i=1;i<=n;i++)
        {
            ans = max(ans, p[i]+rc(p,n-i,r));
        }
    }
     r[n]=ans;
    return ans;
}
int rod_cut(int p[],int n)
{
    int r[1001];
    r[0]=0;
    for(int i=1;i<=n;i++)
        r[i]=-1;
    return rc(p,n,r);
}
int main()
{
    int p[1001];
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        p[0]=0;
        for(i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        cout<<rod_cut(p,n)<<endl;
    }
    return 0;
}
