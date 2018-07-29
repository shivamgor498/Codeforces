/* shivamgor498
	http://codeforces.com/gym/101128
	H - Sheldon Numbers
	Explanation:- Generate all possible string with continous 1 and 0 of length (1..n) and (0..m) respectively for each string generated check if it is in range and each element sheldon number is set so that u get distinct values*/
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
typedef unsigned long long int ull;
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
}
ull x,y;
set<ull> checkset;
bool bTD(string n) // range checker
{
    string num = n;
    ull dec_value = 0;
    ull base = 1;

    int len = num.length();
    for (int i=len-1;i>=0;i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
        if(dec_value>y)
          return false;
    }
    if(dec_value>=x&&dec_value<=y)
    {
    		checkset.insert(dec_value);
      return true;
     }
    return false;
}
int main()
{
	ios
	ll t;
	//cin >> t;
	t = 1;
	while(t--)
	{
		ll ans = 0;
		cin >> x>>y;	 	
		for(int i=1;i<=63;i++) // sheldon numbers of bit length i
		{
			for(int j=1;j<=63;j++) // continous length of 1 is j
			{
				string temp="";
				for(int l=0;l<j;l++)
					temp+='1';
				for(int k=0;k<=63;k++)// continous length of 0 is k
				{
					string temp1 = "",s="";
					int cnt=0;
					for(int m=0;m<k;m++)
						temp1+='0';
					cnt = i/(j+k);
					for(int w=0;w<cnt;w++)
					{
						s+=temp;
						s+=temp1;
					}
					if(i%(j+k))
						s+=temp;
					if(bTD(s))
						ans++;
				}
			}
		}
		cout << checkset.size() << "\n";		
	}
}
