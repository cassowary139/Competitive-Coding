#include <bits/stdc++.h>
#define MAX 200005
using namespace std;
int F[MAX];
void compute(string b,int m)
{
    int i,j;
    i = 1;
    j = 0;
    F[0] = 0;
    while(i<m)
    {
        if(b[i]==b[j])
        {
            F[i] = j+1;
            i++;
            j++;
        }
        else if(j>0)
        {
            j = F[j-1];
        }
        else
        {
            F[i] = 0;
            i++;
        }
    }
}
int main()
{
    int i;
    string a;
    while(getline(cin,a))
    {
    int n,m;
    string b;
    //cout<<a<<endl;
    b = a; //b is a copy of original string
    //cout<<b<<endl;
    n = a.size();
    if(n==1)
        cout<<a<<endl;
    else
    {
        m = 2*n;
        reverse(b.begin(),b.end());
        b = b+a;
        //cout<<b<<endl;
        compute(b,m);
        if(F[m-1]>=n)
            cout<<a<<endl;
        else
        {
            cout<<a;
            for(i=F[m-1];i<n;i++)
                cout<<b[i];
            cout<<endl;
        }
    }
    }
    return 0;
}
