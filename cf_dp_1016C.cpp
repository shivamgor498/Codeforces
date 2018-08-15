/* shivamgor498
	http://codeforces.com/contest/1016/problem/C
	Explanation :-  http://codeforces.com/blog/entry/61015 */

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
	//cin >> t;
	t = 1;
	while(t--){
		ll n,ans=0,tans=0;
		cin >> n;
		ll a[2][n],sumright[2][n+5],sumleft[2][n+5],sum[2][n+5];
		for(int i=0;i<2;i++)
			for(int j=0;j<n;j++)
				cin >> a[i][j];
		for(int i=0;i<2;i++)
			for(int j=0;j<=n;j++)
			{
				sumright[i][j] = 0;
				sumleft[i][j] = 0;
				sum[i][j] = 0;
			}
		for(int i=0;i<2;i++)
			for(int j=n-1;j>=0;j--)
			{
				sumright[i][j] = sumright[i][j+1] + (j+1)*a[i][j]; // traversing right from j th column to (n-1)th column
				sumleft[i][j] = sumleft[i][j+1] + (n-j)*a[i][j]; // traversing left from (n-1)th to jth column
				sum[i][j] = sum[i][j+1] + a[i][j]; // suffix sum will be used  for calculating paths
			}
		int i = 0;
		for(int j=0;j<n;j++)
		{
			ll fans = tans;
			fans+=(sumright[i][j]+(j*sum[i][j])); // j*sum[i][j] is added because after zigzag path j times more mushroom will be grown
			fans+=(sumleft[(i+1)%2][j] + (j+n)*sum[(i+1)%2][j]); //(j+n)*sum[i][j] is added same for zigzag apth
			ans = max(ans,fans);
			tans+=(a[i][j]*(2*j + 1)); // adding zigzag elements in final answer
			tans+=(a[(i+1)%2][j]*(2*j + 2));
			i++;
			i%=2;
		}
		for(int j=0;j<n;j++)
			ans-=(a[0][j] + a[1][j]);
		cout << ans;
	}
}
