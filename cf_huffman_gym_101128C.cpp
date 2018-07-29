/* shivamgor498
	http://codeforces.com/gym/101128
	C - Canvas Painting
	Explanation - split array in tree form and keep big size canvas as up as possible so that they are not painted again and small size canvas as low as possible final answer will be sum of whole tree except root basically this is huffman tree
	example :-
	1) 5 3 5 7
	sort :- 3 5 5 7         sum          20
		3 5 5      7                13       7
        3 5     5                   8    5        
       3    5                     3   5             
       answer is :- 3+5+5+7+8+5+7+13+7 = 40
     2) 4 7 7
        4 7 7            sum         18
      4 7    7                    11     7
     4   7                      4    7
     answer is :- 4+7+7+11 = 29
     3) 1 1 1 100
     	1 1 1 100       sum         103
        1 1 1      100             3      100
      1 1     1                  2   1    
     1   1                     1   1
     answer is :- 1+1+2+1+3+100 = 108
     for this we use priority_queue or min Heap */
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
#define x first
#define y second
using namespace std;
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
int main()
{
	ios
	ll t;
	cin >> t;
	//t = 1;
	while(t--)
	{
		ll n,ans=0;
		cin >> n;
		vector<ll>a(n);
		for(int i=0;i<n;i++)
			cin >> a[i];
		priority_queue<ll,vector<ll>,greater<ll>>pq;
		for(int i=0;i<n;i++)
			pq.push(a[i]);
		while(pq.size()!=1)
		{
			ll ans_temp = pq.top();
			pq.pop();
			ans_temp+=pq.top();
			pq.pop(); // remove first two elements from min Heap or priority_queue and add it to min Heap or priority_queue basically we are implementing huffman code
			ans+=ans_temp;
			pq.push(ans_temp);
		}
		cout << ans << "\n";
	}
}
