#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
#define int long long
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
#define vllp vector<pair<ll, ll>>
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
//................ "Peace Be Upon You" ......................................

void solve(){
	int n, ans=2;
    ll l, r;
    cin>>n;
    vllp x(n);
    rep(i, 0, n){
        cin>>x[i].F>>x[i].S;
    }
    if(n<=2){
        cout<<n;
        return;
    }
    sort(x.begin(), x.end());
    l=x[0].F; 
    rep(i, 1, n-1){
        r=x[i+1].F;
        if((x[i].F-x[i].S)>l){
            ans++;
            l=x[i].F;
        }else if((x[i].F+x[i].S)<r){
            ans++;
            l=(x[i].F+x[i].S);
        }else{
            l=x[i].F;
        }
    }
    cout<<ans;
}

signed main(){
    IOS;
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}