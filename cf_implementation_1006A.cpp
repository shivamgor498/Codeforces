/* shivamgor498
	http://codeforces.com/contest/1006/problem/A
	Explanation :-  in first move 1 is replaced with 2 and then in second move 2 is replaced with 1 hence every even number is replaced with its preceding odd number */

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
		{
			cin >> a[i];
			if(a[i]%2==0)
				cout << a[i]-1 << " ";
			else
				cout << a[i] << " ";
		}	
	}
}
