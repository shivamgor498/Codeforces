/* shivamgor498
	http://codeforces.com/contest/1008/problem/A
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
		string s;
		cin >> s;
		int i=0;
		bool ok = true;
		while(i<s.size())
		{
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') // if character is vowel there can be any character after it
				i++;
			else if(s[i]=='n') //if character is 'n' it also acts like a vowel
				i++;
			else if(i<s.size()-1 && (s[i+1]=='a' || s[i+1]=='e' || s[i+1]=='i' || s[i+1]=='o' || s[i+1]=='u')) // string cannot end with consonant other than 'n' so i<s.size()-1 and next character should be vowel
				i++;
			else // word is not in Berlanese
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
