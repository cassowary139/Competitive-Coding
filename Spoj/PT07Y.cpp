#include <bits/stdc++.h>
using namespace std;
vector <int> v[10001];
int state[10001]={0};
set <int> s;
int bfs(int source)
{
    queue <int> q;
    int i,p;
        q.push(source);
        state[source]=1;
        while(!(q.empty()))
        {
            p = q.front();
            q.pop();
            for(i=0;i<v[p].size();i++)
            {
                if(state[v[p][i]]==0)
                {
                    state[v[p][i]]=1;
                    q.push(v[p][i]);
                }
            }
        }
}
int main()
{
    int  n,m,i,ctr,k,a,b;
    cin>>n>>m;
    ctr=0;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    if(m!=(n-1))
        cout<<"NO"<<endl;
    else
    {
    for(i=1;i<=n;i++)
    {
        if(state[i]==0)
        {
            bfs(i);
            ctr++;
        }
    }
    //cout<<ctr<<endl;
    if(ctr==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }
    return 0;
}
