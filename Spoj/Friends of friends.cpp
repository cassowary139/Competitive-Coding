#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n,x,f[10005],nf,len,k;
	int j,i=0;
	set<int> s;
	cin>>n;
	while(n--)
	{
		cin>>k;
		f[i++]=k;
		cin>>nf;
		while(nf--)
		{
			cin>>x;
			s.insert(x);
		}
	}
    for(j=0;j<i;j++)
    {
    	s.erase(f[j]);
	}
	len = s.size();
	cout<<len<<endl;
	return 0;
}
