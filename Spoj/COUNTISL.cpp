#include <bits/stdc++.h>
using namespace std;
char a[205][205];
int n,m;
void bfs(pair <int,int> pi,int state[205][205])
{
    int x,y,i;
    pair <int,int> p;
    queue <pair <int,int> > q;
    q.push(pi);
    state[pi.first][pi.second]=1;
    while(!(q.empty()))
    {
        p = q.front();
        q.pop();
        for(i=0;i<8;i++)
        {
            if(i==0)
            {
                x=p.first-1;
                y=p.second;
            }
            if(i==1)
            {
                x=p.first+1;
                y=p.second;
            }
            if(i==2)
            {
                x=p.first;
                y=p.second-1;
            }
            if(i==3)
            {
                x=p.first;
                y=p.second+1;
            }
            if(i==4)
            {
                x=p.first-1;
                y=p.second-1;
            }
            if(i==5)
            {
                x=p.first+1;
                y=p.second+1;
            }
            if(i==6)
            {
                x=p.first-1;
                y=p.second+1;
            }
            if(i==7)
            {
                x=p.first+1;
                y=p.second-1;
            }
            if(x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]=='#'&&state[x][y]==0)
            {
                state[x][y]=1;
                q.push(make_pair(x,y));
            }
        }
    }
}
int main()
{
    int t,ctr,i,j;
    cin>>t;
    while(t--)
    {
        vector <pair <int,int> > v;
        int state[205][205]={0};
        ctr=0;
        cin>>n>>m;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='#')
                    v.push_back(make_pair(i,j));
            }
        }
        //cout<<v.size()<<endl;
        /**for(i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }**/
        for(i=0;i<v.size();i++)
        {
            if(state[v[i].first][v[i].second]==0)
            {
                bfs(v[i],state);
                ctr++;
            }
        }
        cout<<ctr<<endl;
    }
    return 0;
}
