// Codeforces - 535D - Travas and Malekas
//shivamgor498
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define hell2 1000000006
#define pb push_back
#define x first
#define y second
using namespace std;
vector<ll>z;
void zfunc(string s)// calculates z value at index i such that maximum prefix length for string p starting from index i
{
  ll sz = s.size();
  z.pb(-1);
  ll l=0,r=0;
  for(int i=1;i<sz;i++)
  {
    if(i>r)
    {
      l=i;
      r=i;
      while(r<sz && s[r-l]==s[r])
        r++;
      z.pb(r-l);
      r--;
    }
    else
    {
      ll k = i-l;
      if(z[k]<r-i+1)
        z.pb(z[k]);
      else
      {
        l=i;
        while(r<sz && s[r-l]==s[r])
          r++;
        z.pb(r-l);
        r--;
      }
    }
  }
}
int main(){
	ios
	ll t;
	//cin >> t;
  t = 1;
	while(t--){
      ll n,m;
      string p,s;
      cin >> n >> m >> p;
      vector<ll>a(m+1);
      a[0] = -hell2;
      for(int i=1;i<=m;i++)
        cin >> a[i];
      sort(a.begin(),a.end());
      zfunc(p);
      ll sz = p.size();
      for(int i=0;i<n;i++)
        s+='?';
      for(int i=1;i<=m;i++){
        if((a[i]-a[i-1])>=sz){//whole string p can fit between a[i] and a[i-1]
          for(int j = a[i]-1,k=0;k<sz;k++,j++)
            s[j] = p[k];
        }
        else{//count no. of characters between a[i] and a[i-1] that is they are less than p size in b
        	// tot stores no. of characters present in s from p starting at index i
        	// if z[b] equals present characters that is prefix of remaining characters equals present character therefore they both will form string p else answer is not possible that is answer is 0
          ll b = a[i]-a[i-1];
          ll tot = sz-b;
          if(z[b]==tot)
            for(int j=a[i-1]+sz-1,k = tot;k<sz;k++,j++)
              s[j] = p[k];
          else{
            cout << 0;
            return 0;
          }
        }
      }
      ll ans = 1;
      for(int i=0;i<n;i++)
        if(s[i]=='?') // for each empty character we can put that one of 26 characters this can be done in 26 ways therefore answer is multiplied by 26 for each '?'
          ans = ((ans%hell)*(26))%hell;
      cout << ans;
	}
}
