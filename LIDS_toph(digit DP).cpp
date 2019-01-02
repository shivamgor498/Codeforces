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
ll dp[12][2][2][2][10][10]; // pos,low,high,nonzero,lastelement in LIS,lenght of LIS
vector<ll>mn,mx;
ll tar;
ll fun(ll ind,ll low,ll high,ll nonzero,ll lst,ll len)
{
	if(ind==mn.size())
	{
		if(len==tar)
			return 1;
		else
			return 0;
	}
	if(dp[ind][low][high][nonzero][lst][len]!=-1)
		return dp[ind][low][high][nonzero][lst][len];
	ll ans = 0;
	ll low_limit = 0;
	ll high_limit = 0;
	if(low)
		low_limit = mn[ind];
	else
		low_limit = 0;
	if(high)
		high_limit = mx[ind];
	else
		high_limit = 9;
	for(int i=low_limit;i<=high_limit;i++)
	{
		ll nlo,nhi,nzero;
		if(i==mn[ind])
			nlo = low;
		else
			nlo = 0;
		if(i==mx[ind])
			nhi = high;
		else
			nhi = 0;
		if(i>0 || nonzero)
			nzero = 1;
		else
			nzero = 0;
		if(i>lst && nzero)
			ans+=fun(ind+1,nlo,nhi,nzero,i,len+1);
		ans+=fun(ind+1,nlo,nhi,nzero,lst,len);
	}
	dp[ind][low][high][nonzero][lst][len] = ans;
	return dp[ind][low][high][nonzero][lst][len];
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
		cin >> a >> b;
		if(a>b)
			swap(a,b);
		ll temp = a;
		while(temp)
		{
			mn.pb(temp%10);
			temp/=10;
		}
		temp = b;
		while(temp)
		{
			mx.pb(temp%10);
			temp/=10;
		}
		while(mn.size()<mx.size())
			mn.pb(0);
		reverse(all(mn));
		reverse(all(mx));
		for(int i=mx.size();i>=1;i--)
		{
			memset(dp,-1,sizeof(dp));
			tar = i;
			ll ans = fun(0,1,1,0,-1,0); // pos,low,high,nonzero,lst,len
			if(ans>0)
			{
				cout << i << " " << ans << "\n";
				break;
			}
		}
		mn.clear();
		mx.clear();
	}
	return 0;
}

