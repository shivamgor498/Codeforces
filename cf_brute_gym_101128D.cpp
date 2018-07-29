/* shivamgor498
	http://codeforces.com/gym/101128
	D - Dice Cup
	Explanation:- print number from min(n,m)+1 to max(n,m)+1*/
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
#define x first
#define y second
using namespace std;
ll fpow(ll x,ll y){x=x%hell;ll res=1;while(y){if(y&1)res=res*x;res%=hell;y=y>>1;x=x*x;x%=hell;}return res;}
ll inv(ll n)
{
	return fpow(n,hell-2);
}
ll modmul(ll x,ll y){
	return (x*1ll*y)%hell;
}
ll modadd(ll x,ll y){
	ll temp = x%hell + y%hell;
	temp%=hell;
	if(temp<0)
		temp = (temp+hell)%hell;
	return temp;
}
int main()
{
	ios
	ll t;
	cin >> t;
	//t = 1;
	while(t--)
	{
		ll n,m;
		cin >> n >> m;
		ll mn = min(n,m)+1,mx = max(n,m)+1;
		for(int i=mn;i<=mx;i++)
			cout << i << " ";
		cout << "\n";
	}
}
