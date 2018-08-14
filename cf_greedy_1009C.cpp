/* shivamgor498
	http://codeforces.com/contest/1009/problem/C
	Explanation :- here we are not calculating total we are directly calculating sum of the array in this if di <0 then it we will choose center point else we will choose initial point this is optimal approach and xi will always be added n times for each change.*/

#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define hell1 1000000006
#define pb push_back
#define x first
#define y second
using namespace std;
ll mM(ll a,ll b,ll mod){ll res = 0;a %= mod;while(b){if (b & 1)res = (res + a) % mod;a = (2 * a) % mod;b >>= 1;}return res;}
ll fpow(ll x,ll y,ll p){x=x%p;ll res=1;while(y){if(y&1)res=mM(res,x,p);res%=p;if(res<0)res=(res+p)%p;y=y>>1;x=mM(x,x,p);if(x<0)x=(x+p)%p;x%=p;}return res;}
ll inv(ll n){return fpow(n,hell-2,hell);}
ll modmul(ll x,ll y){return mM(x,y,hell);}
ll modadd(ll x,ll y){ll temp=x%hell+y%hell;temp%=hell;if(temp<0)temp = (temp+hell)%hell;return temp;}
int main(){
	ios
	ll t;
	cin >> t;
	//t = 1;
	while(t--){
		ll n,m;
		cin >> n >> m;
		ll ind_max = 1,ind_min = (n+1)/2;
		ll ans = 0;
		ll sum_max = 0,sum_min = 0;
		for(int i=1;i<=n;i++)
		{
			sum_max+=abs(i-ind_max);
			sum_min+=abs(i-ind_min);
		}
		while(m--)
		{
			ll t1,t2;
			cin >> t1 >> t2;
			ans+=(t1*n);
			if(t2>0)
				ans+=t2*sum_max;
			else
				ans+=t2*sum_min;
		}
		long double fans = (1.0*ans)/double(n);
		cout << fixed << setprecision(9) << fans;
	}
}
