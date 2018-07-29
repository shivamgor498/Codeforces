/* shivamgor498
	http://codeforces.com/gym/101128
	Problem :- A- Promotions
	Explanation :- calculate no. of predecessor and successor for each node suppose c no. of promotions are to be made then promotions of node i is certainly possible if successor[i] >= n-c i.e. after doing c promotions n-c nodes will be left and if successor of i >= this number(n-c) then promotion of i is guranteed and promotion of i is not possible if predecessor of i is >= c i.e. before c there are more number of nodes than c there promotions will never reach till i */
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
#define x first
#define y second
using namespace std;
ll a,b,n,p;
vector<ll>adj[5005],visited(5005,0),suc(5005,0),pre(5005,0); // adj is for adjacency list,visited is array used for dfs,suc will store no. of sucessor for i and pre will store no. of predecessor for i
ll isChild[5005][5005]; // isChild[i][j] will be 1 if ( i is parent of j ) or ( j is child of i )
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
void dfs(int src)
{
	visited[src] = 1;
	for(int i=0;i<adj[src].size();i++)
	{
		if(!visited[adj[src][i]])
			dfs(adj[src][i]);
		isChild[src][adj[src][i]] = 1; // adj[src][i] is child of src therefore isChild[src][adj[src][i]] is 1
		for(int j=0;j<n;j++)
			isChild[src][j] = isChild[src][j] | isChild[adj[src][i]][j]; // every sucessor of adj[src][j] is also sucessor of src
	}
}
int main()
{
	ios
	ll t;
	//cin >> t;
	t = 1;
	while(t--)
	{
		for(int i=0;i<5005;i++)
			for(int j=0;j<5005;j++)
				isChild[i][j] = 0;
		cin >> a >> b >> n >> p;
		ll ra = n-a,rb = n-b; // remaining nodes after a promotions and b promotions
		while(p--)
		{
			ll e1,e2;
			cin >> e1 >> e2;
			adj[e1].pb(e2);
		}
		for(int i=0;i<n;i++)
			if(!visited[i])
				dfs(i);
		for(int i=0;i<n;i++)	
			for(int j=0;j<n;j++)
				if(isChild[i][j]) // if j is child of i increment sucessor of i and predecessor of j
				{
					suc[i]++; 
					pre[j]++;
				}
		ll ca=0,cb=0,np=0; // ca for certainly promoted if a promotions,cb for certainly promoted if b promotions,np for not possible promotions
		for(int i=0;i<n;i++) 
		{
			if(suc[i]>=ra)
				ca++;
			if(suc[i]>=rb)
				cb++;
			if(pre[i]>=b)
				np++;
		}
		cout << ca << "\n" << cb << "\n" << np << "\n";
	}
}
