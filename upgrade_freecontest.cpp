#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lim 2000007

using namespace std;

map < ll, ll > mp;
ll a[lim+7],n,k,c[lim+7];
set < ll > s;
set < ll > :: iterator ir;

int main()
{
    IOS;
    freopen("upgrade.inp","r",stdin);
    freopen("upgrade.out","w+",stdout);
    cin>>n>>k;
    for (int i=1; i<=n; i++) 
    {
       ll x; cin>>x;
       mp[x]++;
       s.insert(x);
    }
    ll res = 0;
    for (ir=s.begin(); ir!=s.end(); ir++)
    {
        ll x=*ir;
        if (mp[x] >=  k)
        {
            ll tmp = mp[x] / k;
            mp[x] = mp[x]-tmp*k;
            s.insert(x+1);
            res=res + mp[x];
            mp[x+1] = mp[x+1]+tmp;
          //  cout<<x<<' '<<mp[x]<<"\n";
        }
        else res = res + mp[x];
    }
    cout<<res;
}
