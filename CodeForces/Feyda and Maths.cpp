#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int binexp(int a,int b,int c){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	if(b%2==0){
		return (binexp((a%c*a%c)%c,b/2,c));
	}
	return (a%c*(binexp((a%c*a%c)%c,(b-1)/2,c))%c)%c;
}

int main()
{
	string s;
	cin>>s;
	ll len=s.size(),ans=0;
	for(int i=0;i<len;i++){
		ans=((ans%4*2)%4+((int)(s[i]-'0'))%4)%4;
	}
	cout<<(1+binexp(3,ans,5)+binexp(2,ans,5)+binexp(4,ans,5))%5<<endl;
	return 0;
}
