#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<long long>
#define vip vector<pii>
#define vb vector<bool>
#define vs vector<string>
#define ln cout<<'\n'
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define filein freopen("input.txt", "r" , stdin);freopen("output.txt", "w", stdout);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define arrin(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define vecin(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define setin(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

ll fact(ll n)
{
    if(n==0)
      return 1;
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
ll nPr(ll n, ll r)
{
    return fact(n) / fact(n - r);
}

//.................................... "Peace Be Upon You" ......................................

void solve(){
	ll n, cnt_till_now=0, cnt, ans=0;
    cin>>n;
    vll v;
    vecin(v, n);
    map<int, int> m;
    rep(i, 0, n){
        m[v[i]]++;
    }
    for(auto c:m){
        cnt=c.S;
        if(cnt>2){
            ans+=(cnt*(cnt-1)*(cnt-2)/6);
        }
        if(cnt>1){
            ans+=((cnt*(cnt-1)/2)*cnt_till_now);
        }
        cnt_till_now+=(cnt);
    }
    cout<<ans;
}

signed main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--){
        solve();
        ln;
    }
    return 0;
}