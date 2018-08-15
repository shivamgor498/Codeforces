/* shivamgor498
	http://codeforces.com/contest/1016/problem/D
	Explanation :-  check is xor all inputs elments such that xor of a[i] and b[i] final check should be zero because every in answer matrix comes in one row and one column hance in check each element of matrix comes twice hence final check should be zero if its not zero then its impossible to create such matrix else answer exists ,for answer put xor of ith row i.e. a[i] in last column in answers matrix in ith row and put xor of jth column i.e.b[j] in last row of jth column and all others to 0 except a[n-1][m-1] because it is intersection of last column and last row so we can't put answer directly of a[n-1] or b[m-1] rather answer in this cell will be a[0]^a[1].....a[n-2]^b[m-1] or b[0]^b[1]....b[m-2]^a[n-1] (note ^ represents xor here) */

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
		ll n,m;
		cin >> n >> m;
		vector<ll>a(n),b(m);
		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int i=0;i<m;i++)
			cin >> b[i];
		ll check=0;
		for(int i=0;i<n;i++)
			check^=a[i];
		for(int i=0;i<m;i++)
			check^=b[i];
		if(!check)
		{
			cout << "YES\n";
			ll ans[n][m];
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					ans[i][j] = 0;
			for(int i=0;i<n-1;i++)
				ans[i][m-1] = a[i];
			ll temp = 0;
			for(int i=0;i<m-1;i++)
			{
				ans[n-1][i] = b[i];
				temp^=b[i];
			}
			temp^=a[n-1];
			ans[n-1][m-1] = temp;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
					cout << ans[i][j] << " ";
				cout << "\n";
			}
			
		}
		else
			cout << "NO\n";
	}
}
