#include <bits/stdc++.h>
#define MAX 200005
using namespace std;
int n;
int F[MAX];
string s;
void compute()
{
    int i,j;
    i = 1;
    j = 0;
    F[0] = 0;
    while(i<n)
    {
        if(s[i]==s[j])
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
    int len;
    while(1)
    {
        cin>>s;
        if(s=="*")
            break;
        n = s.length();
        compute();
        len  = n - F[n-1];
        if(n%len==0)
        {
            cout<<n/len<<endl;
        }
        else
            cout<<"1"<<endl;
    }
    return 0;
}
