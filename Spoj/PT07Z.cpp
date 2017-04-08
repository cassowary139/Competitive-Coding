#include <bits/stdc++.h>
using namespace std;
vector <int> v[10004];
int arr[3]={0,1,0};
int main()
{
    int  n,i,a,b,k,l,node;
    cin>>n;
    for(i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    //ans = INT_MIN;
    for(i=1;i<=2;i++)
    {
        int j,p;
        int state[10004]={0};
        int level[10004];
        stack <int> s;
        s.push(arr[i]);
        state[arr[i]]=1;
        level[arr[i]]=0;
        while(!(s.empty()))
        {
            p = s.top();
            s.pop();
            for(j=0;j<v[p].size();j++)
            {
                if(state[v[p][j]]==0)
                {
                    state[v[p][j]]=1;
                    level[v[p][j]]=level[p]+1;
                    s.push(v[p][j]);
                }
            }
        }
        k=INT_MIN;
        for(l=1;l<=n;l++)
        {
            if(level[l]>k)
            {
                k = level[l];
                node = l;
            }
        }
        arr[2]=node;
    }
    cout<<k<<endl;
    return 0;
}
