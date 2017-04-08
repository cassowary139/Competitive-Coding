#include <bits/stdc++.h>
using namespace std;
vector <int> v[1000001];
int state[1000001]={0};
int level[1000001];
int main()
{
    int f,s,g,u,d,i,k,p;
    cin>>f>>s>>g>>u>>d;
    queue <int> q;
    q.push(s);
    state[s]=1;
    level[s]=0;
    while(!(q.empty()))
    {
        p = q.front();
        q.pop();
        for(i=0;i<2;i++)
        {
            k = (i==0)? p+u : p-d;
            if(k>=1&&k<=f)
            {
                if(state[k]==0)
                {
                    state[k]=1;
                    level[k]=level[p]+1;
                    q.push(k);
                }
            }
        }
    }
    if(state[g]==1)
        cout<<level[g]<<endl;
    else
        cout<<"use the stairs"<<endl;
    return 0;
}
