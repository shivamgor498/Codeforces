/* shivamgor498
	http://codeforces.com/contest/25/problem/D
	Simple Disjoint Set Union Problem
	*/
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
#define x first
#define y second
using namespace std;
vector<ll>parent(1005),size(1005);
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
ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
int main()
{
	//ios
	ll t;
	//cin >> t;
	t = 1;
	while(t--)
	{
		ll n,c1,c2;
		cin >> n;
		vector< pair<ll,ll> >extra; // we will maintain an vector of pair for extra roads that we can delete these extra road will be there if by adding this road in its component cycle is formed
		vector<ll>component; // we will also maintain an vector for storing head of each component
		for(int i=1;i<=n;i++) //initialize each node in DSU with parent to itself size of component to 1
		{
			parent[i] = i;
			size[i] = 1;
		}
		for(int i=0;i<n-1;i++)
		{
			cin >> c1 >> c2;
			if(find_set(c1)==find_set(c2)) // if c1(city1) and c2(city2) both are in same components then adding this road will form a cycle in its component so this is extra road that can be deleted so we add it to extra
				extra.pb({c1,c2});
			else
				union_sets(c1,c2); //else make this road by joining c1 and c2
		}
		for(int i=1;i<=n;i++)
			if(find_set(i)==i)
				component.pb(i); //store head of each component in component vector
		if(component.size()==1)
			cout << 0; // if all are already connected no need to delete and add any road
		else
		{
			cout << component.size()-1 << "\n"; // we will have to make component.size()-1 operations to make it connected
			ll counter = 0;
			for(int i=0;i<extra.size();i++)
			{
				cout << extra[i].x << " " << extra[i].y << " " << component[counter] << " " << component[counter+1] << "\n"; //delete extra road and add new road between each component
				counter++;
			}
		}
	}
}
