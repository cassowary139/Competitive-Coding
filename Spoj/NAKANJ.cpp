#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y,i;
    pair<int,int> s,d,p;
    cin>>t;
    while(t--)
    {
        queue <pair <int,int> > q;
        int state[10][10]={0};
        int level[10][10];
        string s1,s2;
        cin>>s1>>s2;
        s.first = s1[0]-'a'+1;
        s.second = s1[1]-'0';
        d.first = s2[0]-'a'+1;
        d.second = s2[1]-'0';
        //cout<<s.first<<" "<<s.second<<endl;
        //cout<<d.first<<" "<<d.second<<endl;
        state[s.first][s.second]=1;
        level[s.first][s.second]=0;
        q.push(s);
        while(!(q.empty()))
        {
            p = q.front();
            q.pop();
            for(i=0;i<8;i++)
            {
                if(i==0)
                {
                    x = p.first-2;
                    y = p.second-1;
                }
                if(i==1)
                {
                    x = p.first-1;
                    y = p.second-2;
                }
                if(i==2)
                {
                    x = p.first-2;
                    y = p.second+1;
                }
                if(i==3)
                {
                    x = p.first-1;
                    y = p.second+2;
                }
                if(i==4)
                {
                    x = p.first+1;
                    y = p.second-2;
                }
                if(i==5)
                {
                    x = p.first+2;
                    y = p.second-1;
                }
                if(i==6)
                {
                    x = p.first+1;
                    y = p.second+2;
                }
                if(i==7)
                {
                    x = p.first+2;
                    y = p.second+1;
                }
                if(x>=1&&x<=8&&y>=1&&y<=8&&state[x][y]==0)
                {
                    state[x][y]=1;
                    level[x][y]=1+level[p.first][p.second];
                    q.push(make_pair(x,y));
                }
            }
        }
        //if(level[d.first][d.second]==1)
            cout<<level[d.first][d.second]<<endl;
    }
    return 0;
}
