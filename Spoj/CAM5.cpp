#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t,n,e,a,b,i,cnt;
    cin>>t;
    while(t--)
    {
        cnt=0;
        cin>>n>>e;
         queue <int> q;
        vector <int> v[100005];
        int state[100005]={0};
        for(i=0;i<e;i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
                        int j;
        for(i=0;i<n;i++)
        {
            if(state[i]==0)
            {
            q.push(i);
            state[i]=1;
            while(!(q.empty()))
            {
                int p = q.front();
                q.pop();
                for(j=0;j<v[p].size();j++)
                {
                    if(state[v[p][j]]==0)
                    {
                //dbg(v[p][i]);
                    q.push(v[p][j]);
                    state[v[p][j]]=1;
                    }
                }
            }
            cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
