// https://vjudge.net/problem/LightOJ-1068
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define hell1 1000000006
#define pb push_back
#define x first
#define y second
#define MAXL 100005
#define all(v) (v).begin(),(v).end()
using namespace std;
ll fpow(ll x,ll y,ll p){x=x%p;ll res=1;while(y){if(y&1)res=(res*x)%p;res%=p;if(res<0)res=(res+p)%p;y=y>>1;x=(x*x)%p;if(x<0)x=(x+p)%p;x%=p;}return res;}
ll dp[12][100][100][2];
ll k;
vector<ll>num;
ll fun(ll ind,ll sum,ll rest,ll n)
{
	//cout << ind << " " << sum << " " << rest << " " << s << "\n";
	if(ind==num.size())
	{
		//cout << n << " " << sum << "\n";
		if(!(n%k) && !(sum%k))
			return 1;
		else
			return 0;
	}
	if(dp[ind][n][sum][rest]!=-1)
		return dp[ind][n][sum][rest];
	ll ans = 0;
	ll limit = 0;
	if(rest==0)
		limit = num[ind];
	else
		limit = 9;
	for(int i=0;i<=limit;i++)
	{
		ll new_rest = rest;
		if(rest==0 && i<limit)
			new_rest = 1;
		ans+=fun(ind+1,(sum+i)%k,new_rest,(n*10 + i)%k);
	}
	dp[ind][n][sum][rest] = ans;
	return dp[ind][n][sum][rest];
}
ll solve(ll n)
{
	memset(dp,-1,sizeof(dp));
	num.clear();
	while(n)
	{
		num.pb(n%10);
		n/=10;
	}
	reverse(all(num));
	//cout << fun(0,0,0,"") << "\n";
	return fun(0,0,0,0);
}
int main(){
	ios
	ll t = 1;
	cin >> t;
	ll cnt = 0;
	while(t--)
	{
		cout << "Case " << ++cnt << ": ";
		ll a,b;
		cin >> a >> b >> k;
		if(k<=82 && k>1)
			cout << solve(b) - solve(a-1) << "\n";
		else if(k==1)
			cout << b-a+1 << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}

