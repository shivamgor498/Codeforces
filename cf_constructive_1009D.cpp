/* shivamgor498
	http://codeforces.com/contest/1009/problem/D
	Explanation :- as graph should be connected so it should contain at least n-1 edges ,after checking this condition for each possible pair of vertices if gcd of vertices is 1 then add this edge to graph at end if n is not zero then graph is impossible else print the graph*/

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
		if(m<n-1)
		{
			cout <<"Impossible\n";
			return 0;
		}
		vector< pair<ll,ll> >v;
		for(ll i = 1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(__gcd(i,j)==1)
				{
					v.pb({i,j});
					m--;
				}
				if(m==0)
				{
					cout << "Possible\n";
					for(auto f:v)
						cout << f.x << " " << f.y << "\n";
					return 0;
				}
			}
		}
		cout <<"Impossible\n";
	}
}
