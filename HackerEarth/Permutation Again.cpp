#include <iostream>
using namespace std;
int main()
{
	int t;
	unsigned long long int result = 0, sum = 0, term,n; 
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1)
		{
		    cout<<"1"<<endl;
		    continue;
		}
	    if(n%2==0) //even
	    {
	    	sum = (n*(n-2))/2;
	    	result = n-1 + sum;
		}
		else//odd
		{
			term = n/2;
			sum = 2*term*term;
			result = n - 2 + sum;
		}
		cout<<result<<endl;
	}
	return 0;
} 
