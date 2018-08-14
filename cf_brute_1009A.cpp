/* shivamgor498
	http://codeforces.com/contest/1009/problem/A
	Explanation :- maintain a queue of bills and for each game check whether bill in front is >= current game if yes then maxim can buy it else he skips this game */

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
		ll n,m,temp;
		cin >>  n >> m;
		vector<ll>c(n);
		queue<ll>a;
		for(int i=0;i<n;i++)
			cin >> c[i];
		for(int i=0;i<m;i++)
		{
			cin >> temp;
			a.push(temp);
		}
		ll cnt = 0,j=0;
		for(int i=0;i<n;i++)
		{
			if(!a.empty() && a.front()>=c[i])
			{
				cnt++;
				a.pop();
			}
		}
		cout << cnt;
	}
}
