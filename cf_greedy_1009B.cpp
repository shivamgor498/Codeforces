/* shivamgor498
	http://codeforces.com/contest/1009/problem/B
	Explanation :- maintain a count for '0' and '1' and '2' if count of '0' is zero and count of '2' is present then print all '1' and then all '2'  or count of '2' is zero and count '0' is there then print all '0' and then all '1' else if count od '0' and '2' both are zero then print all '1' else we can bring all zeros and ones to front by swapping 0 and 1 before first occurence of 2 and there after you can print all ones after first ocuurence of 2 and then remove all ones from remaining string and print remaining string*/

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
		string s;
		cin >> s;
		ll cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='0')
				cnt1++;
			else if(s[i]=='1')
				cnt2++;
			else
				cnt3++;
		}
		if((cnt1 && !cnt3) || (cnt3 && !cnt1))
		{
			for(int i=0;i<cnt1;i++)
				cout << "0";
			for(int i=0;i<cnt2;i++)
				cout << "1";
			for(int i=0;i<cnt3;i++)
				cout << "2";
			return 0;
		}
		if(cnt1==0 && cnt3==0)
		{
			for(int i=0;i<cnt2;i++)
				cout << 1;
			return 0;
		}
		vector<string>st;
		string temp = "";
		int i;
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='2')
			{
				for(int j=0;j<cnt1;j++)
					cout << 0;
				for(int j=0;j<cnt2;j++)
					cout << 1;
				break;
			}
			else if(s[i]=='0')
				cnt1++;
			else
				cnt2++;
		}
		cnt2 = 0;
		ll te = i;
		for(;i<s.size();i++)
			if(s[i]=='1')
				cnt2++;
		for(int i=0;i<cnt2;i++)
			cout << 1;
		for(;te<s.size();te++)
			if(s[te]=='1')
			{
				st.pb(temp);
				temp = "";
			}
			else
				temp+=s[te];
		if(temp!="")
			st.pb(temp);
		for(int i=0;i<st.size();i++)
			cout << st[i];	
	}
}
