/* shivamgor498
	http://codeforces.com/contest/1008/problem/B
	*/
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
#define x first
#define y second
using namespace std;
vector<ll>parent(50004),size(50004);
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
}int main()
{
	ios
	ll t;
	//cin >> t;
	t = 1;
	while(t--)
	{
	 // at max there will be one move to rotate rectangle
		ll n,h,w,ans=INT_MIN;
		cin >> n;
		cin >> h >> w;
		bool ok = true;
		ans = max(ans,max(h,w)); // current height will be max of current height and width i.e. if current height is not equal to max then we will rotate rectange by 90 degree so height will become maximum
		n--;
		while(n--)
		{
			cin >> h >> w;
			if(h<=ans || w<=ans) // check if height or width of new rectangle is less than equal to current ans
			{
				if(h<=ans && w<=ans) // if both are less than equal to current answer then choose maximum of both so chance of next elements to satisfy given condition increases and also update answer
					ans = max(h,w);
				else if(h<=ans) // if height of new rectangle is less than equal to answer then update answer
					ans = h;
				else // // if width of new rectangle is less than equal to answer then update answer because we can rotate rectangle by 90 degree and our width will become height
					ans = w;
			}
			else // there is no way to make a non-increasing height sequence
			{
				ok = false;
				break;
			}
		}
		if(ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
