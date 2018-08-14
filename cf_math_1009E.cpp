/* shivamgor498
	http://codeforces.com/contest/1009/problem/E
	Explanation :-  probablity of taking rest on a[0] is 0.5 and hence probablity for a[1] will be 0.5*0.5 i.e. o.25 expected value formula comes out to be a[1]/2 + a[2]/2^2 + a[3]/2^3 + ..... a[n-1]/2^(n-1) + a[n]/2^(n-1) for a[n] denominator is 2^(n-1) because last rest is considered in moscow so its resting probablity becomes probablity[n-1]*1.0 = probablity[n-1] */

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
		ll n;
		cin >> n;
		vector<ll>a(n);
		for(int i=0;i<n;i++)
			cin >> a[i];
		vector<ll>pow2(1,1);
		while(pow2.size()<n){
			ll temp = ((pow2[pow2.size()-1]%hell)*(2%hell))%hell;
			pow2.pb(temp);
		}
		ll ans = 0,cur = modmul(pow2[n-1],a[0]);
		for(int i=0;i<n;i++)
		{
			ans = modadd(ans,cur);
			if(i<n-1)
			{
				cur = modadd(cur,-1*modmul(pow2[n-2-i],a[i]));
				cur = modadd(cur,modmul(pow2[n-2-i],a[i+1]));
			}
		}
		cout << ans;
	}
}
