#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll a[30005];
vector<ll> b[1000];
ll block_size;
vector<ll>::iterator it;
ll query(ll l,ll r, ll x)
{
    ll cnt,b1,b2,i,beg,end;
    cnt = 0;
    b1 = l/block_size;
    b2 = r/block_size;
    if(b1==b2)
    {
        for(i=l;i<=r;i++)
        {
            if(a[i]>x)
                cnt++;
        }
    }
    else
    {
        beg = (b2*block_size);
        end = (b1+1)*block_size - 1;
        for(i = l ; i <= end; i++)
        {
            if(a[i]>x)
                cnt++;
        }
        for(i = b1+1 ; i<= b2-1; i++)
        {
            if(binary_search(b[i].begin(),b[i].end(),x))
            {
                it = lower_bound(b[i].begin(),b[i].end(),x);
                //cout<<b[i].end()-it-1<<endl;
                cnt += (b[i].end()-it-1);
            }
            else
            {
                it = it = lower_bound(b[i].begin(),b[i].end(),x);
                //cout<<b[i].end()-it<<endl;
                cnt += (b[i].end()-it);
            }
        }
        for(i = beg; i<=r ; i++)
        {
            if(a[i]>x)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    ll n,i,j,k,q,l,r,x,ans;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    block_size = ceil(sqrt(n));
    k = (n-1)/block_size; //last block
    for(i=0;i<n;i++)
    {
        b[i/block_size].push_back(a[i]);
    }
    for(i=0;i<=k;i++)
    {
        sort(b[i].begin(),b[i].end());
    }
    scanf("%lld",&q);
    ans = 0;
    while(q--)
    {
        cin>>l>>r>>x;
        l = l^ans;
        r = r^ans;
        x = x^ans;
        if(l<1)
            l = 1;
        l--;
        if(r>n)
            r = n;
        r--;
        if(l>r)
            ans = 0;
        else
            ans = query(l,r,x);
        printf("%lld\n",ans);
    }
    return 0;
}
